#!/bin/sh

# create ${doxy_path_out}/index.htm and all files 
# start script in doc/ or src/
# doxy_path_out="<base>/doc/gcad"

# UPDATE files src/gcad_version and src/gcad_date
# ReCreate documentation:   ./gcad_doxygen.sh

# necessary vars: gcad_dir_dev gcad_dir_bin (../options.sh)



# path from doxygen-outputDirectory -> srcBase
dox_path_src="${gcad_dir_dev}src"
export dox_path_src

# path from doxygen-InputfileDirectory -> sourceBasedirectory
# start create doc here ..
srcBase="${dox_path_src}/APP"

# path from srcBase -> doxygen-InputfileDirectory
doxBase="${gcad_dir_dev}doc/gcad_doxygen"

# path from srcBase -> doxygen-outputDirectory
doxy_path_out="${gcad_dir_dev}doc/gcad"
export doxy_path_out

# doxgen will remove gcad_dir_dev from all filenames
# see STRIP_FROM_PATH in Doxyfile




# version, date, project-name
version=`cat ${dox_path_src}/gcad_version`
date=`cat ${dox_path_src}/gcad_date`
doxy_prj_nam="gCAD3D $version"
export doxy_prj_nam


# sourcedirectories
srcDirs="\
 ../APP\
 ../xa\
 ../ut\
 ../gr\
 ../ci\
 ../db\
 ../exp\
 ../prc\
 ../gui\
 ../gui_gtk2\
 ../gui_gtk3\
"
export srcDirs

echo "srcDirs = " ${srcDirs}

# all dox-files; this makes the main-menu.
# Do not change first line (sourcedirectories)
myFiles="${srcDirs}\
 ${doxBase}/mainpage.dox\
 ${doxBase}/Introduction.dox\
 ${doxBase}/Sourcefiles_gcad.dox\
 ${doxBase}/Sourcefiles_gui.dox\
 ${doxBase}/Download.dox\
 ${doxBase}/TODO.dox\
 ${doxBase}/ruler1.dox\
 ${doxBase}/Plugins.dox\
 ${doxBase}/Userinteractions.dox\
 ${doxBase}/Messages.dox\
 ${doxBase}/Objects-Create.dox\
 ${doxBase}/Objects-Resolve.dox\
 ${doxBase}/ObjectFormatConversions.dox\
 ${doxBase}/Attributes.dox\
 ${doxBase}/Debugging.dox\
 ${doxBase}/Constants-Tolerances.dox\
 ${doxBase}/ruler2.dox\
 ${doxBase}/Tools-MemoryFunctions.dox\
 ${doxBase}/Tools-TextFunctions.dox\
 ${doxBase}/Tools-GeometricFunctions.dox\
 ${doxBase}/Tools-MathNumericFunctions.dox\
 ${doxBase}/Tools-OperatingSystemFunctions.dox\
 ${doxBase}/ruler3.dox\
 ${doxBase}/Programming-Helpfiles.dox\
 ${doxBase}/Objects-Format.dox\
 ${doxBase}/Tables-Format.dox\
 ${doxBase}/DataBase.dox\
 ${doxBase}/File-Format-native.dox\
 ${doxBase}/File-Format-binary.dox\
 ${doxBase}/ProgramFlow.dox\
 ${doxBase}/Programminginfos.dox\
 ${doxBase}/NamingConventions.dox\
 ${doxBase}/DevDoc_hints.dox\
 ${doxBase}/ruler4.dox
"
export myFiles


############# work ..
echo "cd $srcBase"
cd $srcBase


# update version & date in mainpage.dox
cat ${doxBase}/mainpage | sed "s/<VERSION>/$version/"  | sed "s/<DATE>/$date/" > ${doxBase}/mainpage.dox
#exit


# update version in Download.dox
cat ${doxBase}/Download | sed "s/<VERSION>/$version/g" > ${doxBase}/Download.dox
#exit


#-------------------------------------------------------
# create file ../src/APP/srcFiles (a list of sourcefiles)
# get bitNr DIR_DEV gcad_dir_dev gcad_dir_bin
echo "Create list of sourcefiles"
make -f ${gcad_dir_dev}/src/APP/gcad3d.mak srclst

echo "doxy_help1 Sourcefiles_gcad"
${gcad_dir_dev}/src/APP/doxy_help1.sh "Sourcefiles_gcad"
mv -f Sourcefiles.dox ${doxBase}/Sourcefiles_gcad.dox
#vi ${doxBase}/Sourcefiles_gcad.dox
#exit


#-------------------------------------------------------
# create Sourcefiles_gui.dox
echo "Create list of GUI-files"
# create file ../src/APP/srcFiles (a list of sourcefiles)
make -f gcad_gui_lnk.mak srclst

echo "doxy_help1 Sourcefiles_gui"
${gcad_dir_dev}/src/APP/doxy_help1.sh "Sourcefiles_gui"
mv -f Sourcefiles.dox ${doxBase}/Sourcefiles_gui.dox
#vi ${doxBase}/Sourcefiles_gui.dox
#exit


#-------------------------------------------------------
# clear outDir, but keep .gitignore
echo "Clear ${doxy_path_out}"
rm -rf ${doxy_path_out}/*


# copy image
cp ${doxBase}/*.jpg ${doxy_path_out}/.


# start doxygen
# doxygen-input: $doxy_prj_nam $doxy_path $myFiles and file Doxyfile
doxygen ${doxBase}/Doxyfile


# display new docu
#xdg-open ${doxy_path_out}/index.htm

exit
# EOF
