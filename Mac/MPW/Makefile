# MPW Makefile to build Python as a shared library.
# This uses the development environment distributed on the OpenDoc CD:
# compiler (SC) is Symantec C for MPW, headers are Universal Headers.
# Running Python requires that the extensions CFM-68K and MixedModeInit are
# installed, and that the various shared libraries are in the Extensions folder.

##########################
# Configurable variables #
##########################

Top = :::
CC = SC
CFlagsNoInclude = -woff -e -model cfmseg -b �
	-d HAVE_CONFIG_H=1 -d MPW=1 -d USE_MAC_SHARED_LIBRARY=1 -d USE_MAC_APPLET_SUPPORT
PythonIncludes = -i "{Top}"Mac: -i "{Top}"Include:
MacIncludes = -i "{CIncludes}"
CFlagsMac = {CFlagsNoInclude} {MacIncludes} {PythonIncludes}
CFlags = {CFlagsNoInclude} {PythonIncludes} {MacIncludes}
Objs = :Objs:
ExtensionsFolder = {SystemFolder}Extensions:

########################
# List of object files #
########################

ALL = �
	"{Objs}"acceler.c.o �
	"{Objs}"accessobject.c.o �
	"{Objs}"arraymodule.c.o �
	"{Objs}"atof.c.o �
	"{Objs}"strtod.c.o �
	"{Objs}"audioop.c.o �
	"{Objs}"bltinmodule.c.o �
	"{Objs}"ceval.c.o �
	"{Objs}"chdir.c.o �
	"{Objs}"classobject.c.o �
	"{Objs}"compile.c.o �
	"{Objs}"config.c.o �
	"{Objs}"errors.c.o �
	"{Objs}"fileobject.c.o �
	"{Objs}"floatobject.c.o �
#	"{Objs}"fmod.c.o �
	"{Objs}"frameobject.c.o �
	"{Objs}"funcobject.c.o �
	"{Objs}"gestaltmodule.c.o �
	"{Objs}"getargs.c.o �
	"{Objs}"getbootvol.c.o �
	"{Objs}"getopt.c.o �
	"{Objs}"getwd.c.o �
	"{Objs}"graminit.c.o �
	"{Objs}"grammar1.c.o �
	"{Objs}"imageop.c.o �
	"{Objs}"import.c.o �
	"{Objs}"importdl.c.o �
	"{Objs}"intobject.c.o �
	"{Objs}"intrcheck.c.o �
	"{Objs}"listobject.c.o �
	"{Objs}"longobject.c.o �
	"{Objs}"macfsmodule.c.o �
	"{Objs}"macgetargv.c.o �
	"{Objs}"macgetmtime.c.o �
	"{Objs}"macglue.c.o �
	"{Objs}"macguesstabsize.c.o �
	"{Objs}"macmodule.c.o �
	"{Objs}"macosmodule.c.o �
	"{Objs}"macsetfiletype.c.o �
	"{Objs}"macshlglue.c.o �
	"{Objs}"macstat.c.o �
	"{Objs}"mappingobject.c.o �
	"{Objs}"marshal.c.o �
#	"{Objs}"mathmodule.c.o �
	"{Objs}"md5c.c.o �
	"{Objs}"md5module.c.o �
	"{Objs}"methodobject.c.o �
	"{Objs}"mkdir.c.o �
	"{Objs}"modsupport.c.o �
	"{Objs}"moduleobject.c.o �
	"{Objs}"myreadline.c.o �
	"{Objs}"mystrtoul.c.o �
	"{Objs}"nfullpath.c.o �
	"{Objs}"node.c.o �
	"{Objs}"object.c.o �
	"{Objs}"opendir.c.o �
	"{Objs}"parser.c.o �
	"{Objs}"parsermodule.c.o �
	"{Objs}"parsetok.c.o �
	"{Objs}"pythonmain.c.o �
	"{Objs}"pythonrun.c.o �
	"{Objs}"rangeobject.c.o �
	"{Objs}"regexmodule.c.o �
	"{Objs}"regexpr.c.o �
	"{Objs}"rgbimgmodule.c.o �
	"{Objs}"rmdir.c.o �
	"{Objs}"rotormodule.c.o �
	"{Objs}"sigcheck.c.o �
	"{Objs}"stringobject.c.o �
	"{Objs}"stropmodule.c.o �
	"{Objs}"structmember.c.o �
	"{Objs}"structmodule.c.o �
	"{Objs}"sync.c.o �
	"{Objs}"sysmodule.c.o �
	"{Objs}"timemodule.c.o �
	"{Objs}"tokenizer.c.o �
	"{Objs}"traceback.c.o �
	"{Objs}"tupleobject.c.o �
	"{Objs}"typeobject.c.o �
	"{Objs}"AEmodule.c.o �
	"{Objs}"Ctlmodule.c.o �
	"{Objs}"Dlgmodule.c.o �
	"{Objs}"Evtmodule.c.o �
	"{Objs}"Menumodule.c.o �
	"{Objs}"Qdmodule.c.o �
	"{Objs}"Resmodule.c.o �
	"{Objs}"Sndmodule.c.o �
	"{Objs}"Winmodule.c.o �
	"{Objs}"ctbmodule.c.o �
#	"{Objs}"imgformat.c.o �
#	"{Objs}"macmain.c.o �
#	"{Objs}"stdwinmodule.c.o �

################
# Main targets #
################

# Default target
all � PythonLib.slb PythonApplet

# Install stuff
install � PythonLib.slb
	Duplicate -y PythonLib.slb "{ExtensionsFolder}"

# Uninstall stuff
uninstall �
	Delete -i "{ExtensionsFolder}"PythonLib.slb

# Delete intermediate build stuff and other temporary cruft
clean �
	Delete -i "{Objs}"�.o
	Delete -i PythonLib PythonApplet xxmodule
	Delete -i stdout stderr
	Delete -i �.pyc

# Delete everything that can be reconstructed
clobber � clean
	Delete -i �.slb �.NJ

# Build 'xx' as a dynamically loadable module
xx � xxmodule.slb

# Clean up (somewhat)

#########################
# Build Applet template #
#########################

PythonApplet � PythonLib.slb "{Objs}"macapplet.c.o
	ILink �
		-o PythonApplet �
		-xm e �
		-model cfmseg �
		-c PYTa �
		"{Objs}"macapplet.c.o �
		"{CLibraries}"NuStdCLib.slb �
		"{Libraries}"NuInterfaceLib.slb �
		"{Libraries}"MixedModeLib.slb �
		"{Libraries}"NuIntEnv.slb �
		"{Libraries}"NuMathLib.o �
		"{Libraries}"NuMacRuntime.o �
		PythonLib.slb

####################################
# Build Python as a shared library #
####################################

Exports = PyExc_AttributeError

PythonLib.slb � {ALL}
	ILink �
		-o PythonLib �
		-xm s �
		-model cfmseg �
		-init __SINIT �
		-export {Exports} �
		"{CLibraries}"NuStdCLib.slb �
		"{Libraries}"NuInterfaceLib.slb �
		"{Libraries}"MixedModeLib.slb �
		"{Libraries}"NuIntEnv.slb �
		"{Libraries}"NuMathLib.o �
		"{Libraries}"NuMacRuntime.o �
		{ALL}
	MakeFlat PythonLib -o PythonLib.slb
	Echo "delete 'cfrg'(0);" | Rez -o PythonLib -a -m

#############################################
# Build xx as a dynamically loadable module #
#############################################

xxmodule.slb � PythonLib.slb "{Objs}"xxmodule.c.o
	ILink �
		-o xxmodule �
		-xm s �
		-model cfmseg �
		-m initxx �
		"{Objs}"xxmodule.c.o �
		"{CLibraries}"NuStdCLib.slb �
		"{Libraries}"NuInterfaceLib.slb �
		"{Libraries}"MixedModeLib.slb �
		"{Libraries}"NuIntEnv.slb �
		"{Libraries}"NuMathLib.o �
		"{Libraries}"NuMacRuntime.o �
		PythonLib.slb
	MakeFlat xxmodule -o xxmodule.slb
	Echo "delete 'cfrg'(0);" | Rez -o xxmodule -a -m
	Echo "delete 'cfrg'(0);" | Rez -o xxmodule.slb -a -m

##############################################
# Targets to create the various object files #
##############################################

"{Objs}"macapplet.c.o � "{Top}"Mac:macapplet.c
	{CC} "{Top}"Mac:macapplet.c -o "{Objs}"macapplet.c.o -s macapplet.c {CFlags}

"{Objs}"macmain.c.o � "{Top}"Mac:macmain.c
	{CC} "{Top}"Mac:macmain.c -o "{Objs}"macmain.c.o -s macmain.c {CFlags}

"{Objs}"pythonmain.c.o � "{Top}"Python:pythonmain.c
	{CC} "{Top}"Python:pythonmain.c -o "{Objs}"pythonmain.c.o -s pythonmain.c {CFlags}

"{Objs}"compile.c.o � "{Top}"Python:compile.c
	{CC} "{Top}"Python:compile.c -o "{Objs}"compile.c.o -s compile.c {CFlags}

"{Objs}"mystrtoul.c.o � "{Top}"Python:mystrtoul.c
	{CC} "{Top}"Python:mystrtoul.c -o "{Objs}"mystrtoul.c.o -s mystrtoul.c {CFlags}

"{Objs}"gestaltmodule.c.o � "{Top}"Mac:gestaltmodule.c
	{CC} "{Top}"Mac:gestaltmodule.c -o "{Objs}"gestaltmodule.c.o -s gestaltmodule.c {CFlags}

"{Objs}"macfsmodule.c.o � "{Top}"Mac:macfs:macfsmodule.c
	{CC} "{Top}"Mac:macfs:macfsmodule.c -o "{Objs}"macfsmodule.c.o -s macfsmodule.c {CFlags}

"{Objs}"macosmodule.c.o � "{Top}"Mac:macosmodule.c
	{CC} "{Top}"Mac:macosmodule.c -o "{Objs}"macosmodule.c.o -s macosmodule.c {CFlags}

"{Objs}"nfullpath.c.o � "{Top}"Mac:macfs:nfullpath.c
	{CC} "{Top}"Mac:macfs:nfullpath.c -o "{Objs}"nfullpath.c.o -s nfullpath.c {CFlags}

"{Objs}"tokenizer.c.o � "{Top}"Parser:tokenizer.c
	{CC} "{Top}"Parser:tokenizer.c -o "{Objs}"tokenizer.c.o -s tokenizer.c {CFlags}

"{Objs}"chdir.c.o � "{Top}"Mac:chdir.c
	{CC} "{Top}"Mac:chdir.c -o "{Objs}"chdir.c.o -s chdir.c {CFlags}

"{Objs}"config.c.o � "{Top}"Mac:config.c
	{CC} "{Top}"Mac:config.c -o "{Objs}"config.c.o -s config.c {CFlags}

"{Objs}"getopt.c.o � "{Top}"Python:getopt.c
	{CC} "{Top}"Python:getopt.c -o "{Objs}"getopt.c.o -s getopt.c {CFlags}

"{Objs}"getwd.c.o � "{Top}"Mac:getwd.c
	{CC} "{Top}"Mac:getwd.c -o "{Objs}"getwd.c.o -s getwd.c {CFlags}

"{Objs}"structmember.c.o � "{Top}"Python:structmember.c
	{CC} "{Top}"Python:structmember.c -o "{Objs}"structmember.c.o -s structmember.c {CFlags}

"{Objs}"stropmodule.c.o � "{Top}"Modules:stropmodule.c
	{CC} "{Top}"Modules:stropmodule.c -o "{Objs}"stropmodule.c.o -s stropmodule.c {CFlags}

"{Objs}"acceler.c.o � "{Top}"Parser:acceler.c
	{CC} "{Top}"Parser:acceler.c -o "{Objs}"acceler.c.o -s acceler.c {CFlags}

"{Objs}"graminit.c.o � "{Top}"Python:graminit.c
	{CC} "{Top}"Python:graminit.c -o "{Objs}"graminit.c.o -s graminit.c {CFlags}

"{Objs}"grammar1.c.o � "{Top}"Parser:grammar1.c
	{CC} "{Top}"Parser:grammar1.c -o "{Objs}"grammar1.c.o -s grammar1.c {CFlags}

"{Objs}"macguesstabsize.c.o � "{Top}"Mac:macguesstabsize.c
	{CC} "{Top}"Mac:macguesstabsize.c -o "{Objs}"macguesstabsize.c.o -s macguesstabsize.c {CFlags}

"{Objs}"node.c.o � "{Top}"Parser:node.c
	{CC} "{Top}"Parser:node.c -o "{Objs}"node.c.o -s node.c {CFlags}

"{Objs}"parser.c.o � "{Top}"Parser:parser.c
	{CC} "{Top}"Parser:parser.c -o "{Objs}"parser.c.o -s parser.c {CFlags}

"{Objs}"parsetok.c.o � "{Top}"Parser:parsetok.c
	{CC} "{Top}"Parser:parsetok.c -o "{Objs}"parsetok.c.o -s parsetok.c {CFlags}

"{Objs}"classobject.c.o � "{Top}"Objects:classobject.c
	{CC} "{Top}"Objects:classobject.c -o "{Objs}"classobject.c.o -s classobject.c {CFlags}

"{Objs}"import.c.o � "{Top}"Python:import.c
	{CC} "{Top}"Python:import.c -o "{Objs}"import.c.o -s import.c {CFlags}

"{Objs}"importdl.c.o � "{Top}"Python:importdl.c
	{CC} "{Top}"Python:importdl.c -o "{Objs}"importdl.c.o -s importdl.c {CFlags}

"{Objs}"macgetmtime.c.o � "{Top}"Mac:macgetmtime.c
	{CC} "{Top}"Mac:macgetmtime.c -o "{Objs}"macgetmtime.c.o -s macgetmtime.c {CFlags}

"{Objs}"macsetfiletype.c.o � "{Top}"Mac:macsetfiletype.c
	{CC} "{Top}"Mac:macsetfiletype.c -o "{Objs}"macsetfiletype.c.o -s macsetfiletype.c {CFlags}

"{Objs}"macstat.c.o � "{Top}"Mac:macstat.c
	{CC} "{Top}"Mac:macstat.c -o "{Objs}"macstat.c.o -s macstat.c {CFlags}

"{Objs}"macshlglue.c.o � "{Top}"Mac:macshlglue.c
	{CC} "{Top}"Mac:macshlglue.c -o "{Objs}"macshlglue.c.o -s macshlglue.c {CFlags}

"{Objs}"marshal.c.o � "{Top}"Python:marshal.c
	{CC} "{Top}"Python:marshal.c -o "{Objs}"marshal.c.o -s marshal.c {CFlags}

"{Objs}"timemodule.c.o � "{Top}"Modules:timemodule.c
	{CC} "{Top}"Modules:timemodule.c -o "{Objs}"timemodule.c.o -s timemodule.c {CFlags}

"{Objs}"fileobject.c.o � "{Top}"Objects:fileobject.c
	{CC} "{Top}"Objects:fileobject.c -o "{Objs}"fileobject.c.o -s fileobject.c {CFlags}

"{Objs}"frameobject.c.o � "{Top}"Objects:frameobject.c
	{CC} "{Top}"Objects:frameobject.c -o "{Objs}"frameobject.c.o -s frameobject.c {CFlags}

"{Objs}"funcobject.c.o � "{Top}"Objects:funcobject.c
	{CC} "{Top}"Objects:funcobject.c -o "{Objs}"funcobject.c.o -s funcobject.c {CFlags}

"{Objs}"intobject.c.o � "{Top}"Objects:intobject.c
	{CC} "{Top}"Objects:intobject.c -o "{Objs}"intobject.c.o -s intobject.c {CFlags}

"{Objs}"listobject.c.o � "{Top}"Objects:listobject.c
	{CC} "{Top}"Objects:listobject.c -o "{Objs}"listobject.c.o -s listobject.c {CFlags}

"{Objs}"mappingobject.c.o � "{Top}"Objects:mappingobject.c
	{CC} "{Top}"Objects:mappingobject.c -o "{Objs}"mappingobject.c.o -s mappingobject.c {CFlags}

"{Objs}"methodobject.c.o � "{Top}"Objects:methodobject.c
	{CC} "{Top}"Objects:methodobject.c -o "{Objs}"methodobject.c.o -s methodobject.c {CFlags}

"{Objs}"moduleobject.c.o � "{Top}"Objects:moduleobject.c
	{CC} "{Top}"Objects:moduleobject.c -o "{Objs}"moduleobject.c.o -s moduleobject.c {CFlags}

"{Objs}"object.c.o � "{Top}"Objects:object.c
	{CC} "{Top}"Objects:object.c -o "{Objs}"object.c.o -s object.c {CFlags}

"{Objs}"stringobject.c.o � "{Top}"Objects:stringobject.c
	{CC} "{Top}"Objects:stringobject.c -o "{Objs}"stringobject.c.o -s stringobject.c {CFlags}

"{Objs}"tupleobject.c.o � "{Top}"Objects:tupleobject.c
	{CC} "{Top}"Objects:tupleobject.c -o "{Objs}"tupleobject.c.o -s tupleobject.c {CFlags}

"{Objs}"accessobject.c.o � "{Top}"Objects:accessobject.c
	{CC} "{Top}"Objects:accessobject.c -o "{Objs}"accessobject.c.o -s accessobject.c {CFlags}

"{Objs}"floatobject.c.o � "{Top}"Objects:floatobject.c
	{CC} "{Top}"Objects:floatobject.c -o "{Objs}"floatobject.c.o -s floatobject.c {CFlags}

"{Objs}"longobject.c.o � "{Top}"Objects:longobject.c
	{CC} "{Top}"Objects:longobject.c -o "{Objs}"longobject.c.o -s longobject.c {CFlags}

"{Objs}"typeobject.c.o � "{Top}"Objects:typeobject.c
	{CC} "{Top}"Objects:typeobject.c -o "{Objs}"typeobject.c.o -s typeobject.c {CFlags}

"{Objs}"ceval.c.o � "{Top}"Python:ceval.c
	{CC} "{Top}"Python:ceval.c -o "{Objs}"ceval.c.o -s ceval.c {CFlags}

"{Objs}"errors.c.o � "{Top}"Python:errors.c
	{CC} "{Top}"Python:errors.c -o "{Objs}"errors.c.o -s errors.c {CFlags}

"{Objs}"intrcheck.c.o � "{Top}"Parser:intrcheck.c
	{CC} "{Top}"Parser:intrcheck.c -o "{Objs}"intrcheck.c.o -s intrcheck.c {CFlags}

"{Objs}"macglue.c.o � "{Top}"Mac:macglue.c
	{CC} "{Top}"Mac:macglue.c -o "{Objs}"macglue.c.o -s macglue.c {CFlags}

"{Objs}"macgetargv.c.o � "{Top}"Mac:macgetargv.c
	{CC} "{Top}"Mac:macgetargv.c -o "{Objs}"macgetargv.c.o -s macgetargv.c {CFlagsMac}

"{Objs}"modsupport.c.o � "{Top}"Python:modsupport.c
	{CC} "{Top}"Python:modsupport.c -o "{Objs}"modsupport.c.o -s modsupport.c {CFlags}

"{Objs}"sigcheck.c.o � "{Top}"Python:sigcheck.c
	{CC} "{Top}"Python:sigcheck.c -o "{Objs}"sigcheck.c.o -s sigcheck.c {CFlags}

"{Objs}"sysmodule.c.o � "{Top}"Python:sysmodule.c
	{CC} "{Top}"Python:sysmodule.c -o "{Objs}"sysmodule.c.o -s sysmodule.c {CFlags}

"{Objs}"traceback.c.o � "{Top}"Python:traceback.c
	{CC} "{Top}"Python:traceback.c -o "{Objs}"traceback.c.o -s traceback.c {CFlags}

"{Objs}"bltinmodule.c.o � "{Top}"Python:bltinmodule.c
	{CC} "{Top}"Python:bltinmodule.c -o "{Objs}"bltinmodule.c.o -s bltinmodule.c {CFlags}

"{Objs}"fopenRF.c.o � "{Top}"Mac:fopenRF.c
	{CC} "{Top}"Mac:fopenRF.c -o "{Objs}"fopenRF.c.o -s fopenRF.c {CFlags}

"{Objs}"stdwinmodule.c.o � "{Top}"Modules:stdwinmodule.c
	{CC} "{Top}"Modules:stdwinmodule.c -o "{Objs}"stdwinmodule.c.o -s stdwinmodule.c {CFlags}

"{Objs}"ctbmodule.c.o � "{Top}"Mac:ctb:ctbmodule.c
	{CC} "{Top}"Mac:ctb:ctbmodule.c -o "{Objs}"ctbmodule.c.o -s ctbmodule.c {CFlags}

"{Objs}"arraymodule.c.o � "{Top}"Modules:arraymodule.c
	{CC} "{Top}"Modules:arraymodule.c -o "{Objs}"arraymodule.c.o -s arraymodule.c {CFlags}

"{Objs}"getbootvol.c.o � "{Top}"Mac:getbootvol.c
	{CC} "{Top}"Mac:getbootvol.c -o "{Objs}"getbootvol.c.o -s getbootvol.c {CFlags}

"{Objs}"macmodule.c.o � "{Top}"Mac:macmodule.c
	{CC} "{Top}"Mac:macmodule.c -o "{Objs}"macmodule.c.o -s macmodule.c {CFlags}

"{Objs}"mkdir.c.o � "{Top}"Mac:mkdir.c
	{CC} "{Top}"Mac:mkdir.c -o "{Objs}"mkdir.c.o -s mkdir.c {CFlags}

"{Objs}"opendir.c.o � "{Top}"Mac:opendir.c
	{CC} "{Top}"Mac:opendir.c -o "{Objs}"opendir.c.o -s opendir.c {CFlags}

"{Objs}"rmdir.c.o � "{Top}"Mac:rmdir.c
	{CC} "{Top}"Mac:rmdir.c -o "{Objs}"rmdir.c.o -s rmdir.c {CFlags}

"{Objs}"sync.c.o � "{Top}"Mac:sync.c
	{CC} "{Top}"Mac:sync.c -o "{Objs}"sync.c.o -s sync.c {CFlags}

"{Objs}"audioop.c.o � "{Top}"Modules:audioop.c
	{CC} "{Top}"Modules:audioop.c -o "{Objs}"audioop.c.o -s audioop.c {CFlags}

"{Objs}"imageop.c.o � "{Top}"Modules:imageop.c
	{CC} "{Top}"Modules:imageop.c -o "{Objs}"imageop.c.o -s imageop.c {CFlags}

"{Objs}"imgformat.c.o � "{Top}"Modules:imgformat.c
	{CC} "{Top}"Modules:imgformat.c -o "{Objs}"imgformat.c.o -s imgformat.c {CFlags}

"{Objs}"macconsole.c.o � "{Top}"Mac:think:macconsole:macconsole.c
	{CC} "{Top}"Mac:think:macconsole:macconsole.c -o "{Objs}"macconsole.c.o -s macconsole.c {CFlags}

"{Objs}"myreadline.c.o � "{Top}"Parser:myreadline.c
	{CC} "{Top}"Parser:myreadline.c -o "{Objs}"myreadline.c.o -s myreadline.c {CFlags}

"{Objs}"pythonrun.c.o � "{Top}"Python:pythonrun.c
	{CC} "{Top}"Python:pythonrun.c -o "{Objs}"pythonrun.c.o -s pythonrun.c {CFlags}

"{Objs}"AEmodule.c.o � "{Top}"Tools:bgen:ae:AEmodule.c
	{CC} "{Top}"Tools:bgen:ae:AEmodule.c -o "{Objs}"AEmodule.c.o -s AEmodule.c {CFlags}

"{Objs}"Ctlmodule.c.o � "{Top}"Tools:bgen:ctl:Ctlmodule.c
	{CC} "{Top}"Tools:bgen:ctl:Ctlmodule.c -o "{Objs}"Ctlmodule.c.o -s Ctlmodule.c {CFlags}

"{Objs}"Dlgmodule.c.o � "{Top}"Tools:bgen:dlg:Dlgmodule.c
	{CC} "{Top}"Tools:bgen:dlg:Dlgmodule.c -o "{Objs}"Dlgmodule.c.o -s Dlgmodule.c {CFlags}

"{Objs}"Evtmodule.c.o � "{Top}"Tools:bgen:evt:Evtmodule.c
	{CC} "{Top}"Tools:bgen:evt:Evtmodule.c -o "{Objs}"Evtmodule.c.o -s Evtmodule.c {CFlags}

"{Objs}"Menumodule.c.o � "{Top}"Tools:bgen:menu:Menumodule.c
	{CC} "{Top}"Tools:bgen:menu:Menumodule.c -o "{Objs}"Menumodule.c.o -s Menumodule.c {CFlags}

"{Objs}"Qdmodule.c.o � "{Top}"Tools:bgen:qd:Qdmodule.c
	{CC} "{Top}"Tools:bgen:qd:Qdmodule.c -o "{Objs}"Qdmodule.c.o -s Qdmodule.c {CFlags}

"{Objs}"Resmodule.c.o � "{Top}"Tools:bgen:res:Resmodule.c
	{CC} "{Top}"Tools:bgen:res:Resmodule.c -o "{Objs}"Resmodule.c.o -s Resmodule.c {CFlags}

"{Objs}"Sndmodule.c.o � "{Top}"Tools:bgen:snd:Sndmodule.c
	{CC} "{Top}"Tools:bgen:snd:Sndmodule.c -o "{Objs}"Sndmodule.c.o -s Sndmodule.c {CFlags}

"{Objs}"Winmodule.c.o � "{Top}"Tools:bgen:win:Winmodule.c
	{CC} "{Top}"Tools:bgen:win:Winmodule.c -o "{Objs}"Winmodule.c.o -s Winmodule.c {CFlags}

"{Objs}"md5c.c.o � "{Top}"Modules:md5c.c
	{CC} "{Top}"Modules:md5c.c -o "{Objs}"md5c.c.o -s md5c.c {CFlags}

"{Objs}"md5module.c.o � "{Top}"Modules:md5module.c
	{CC} "{Top}"Modules:md5module.c -o "{Objs}"md5module.c.o -s md5module.c {CFlags}

"{Objs}"mathmodule.c.o � "{Top}"Modules:mathmodule.c
	{CC} "{Top}"Modules:mathmodule.c -o "{Objs}"mathmodule.c.o -s mathmodule.c {CFlags}

"{Objs}"parsermodule.c.o � "{Top}"Modules:parsermodule.c
	{CC} "{Top}"Modules:parsermodule.c -o "{Objs}"parsermodule.c.o -s parsermodule.c {CFlags}

"{Objs}"regexmodule.c.o � "{Top}"Modules:regexmodule.c
	{CC} "{Top}"Modules:regexmodule.c -o "{Objs}"regexmodule.c.o -s regexmodule.c {CFlags}

"{Objs}"regexpr.c.o � "{Top}"Modules:regexpr.c
	{CC} "{Top}"Modules:regexpr.c -o "{Objs}"regexpr.c.o -s regexpr.c {CFlags}

"{Objs}"rangeobject.c.o � "{Top}"Objects:rangeobject.c
	{CC} "{Top}"Objects:rangeobject.c -o "{Objs}"rangeobject.c.o -s rangeobject.c {CFlags}

"{Objs}"rgbimgmodule.c.o � "{Top}"Modules:rgbimgmodule.c
	{CC} "{Top}"Modules:rgbimgmodule.c -o "{Objs}"rgbimgmodule.c.o -s rgbimgmodule.c {CFlags}

"{Objs}"rotormodule.c.o � "{Top}"Modules:rotormodule.c
	{CC} "{Top}"Modules:rotormodule.c -o "{Objs}"rotormodule.c.o -s rotormodule.c {CFlags}

"{Objs}"structmodule.c.o � "{Top}"Modules:structmodule.c
	{CC} "{Top}"Modules:structmodule.c -o "{Objs}"structmodule.c.o -s structmodule.c {CFlags}

"{Objs}"getargs.c.o � "{Top}"Python:getargs.c
	{CC} "{Top}"Python:getargs.c -o "{Objs}"getargs.c.o -s getargs.c {CFlags}

"{Objs}"xxmodule.c.o � "{Top}"Modules:xxmodule.c
	{CC} "{Top}"Modules:xxmodule.c -o "{Objs}"xxmodule.c.o -s xxmodule.c {CFlags}

"{Objs}"atof.c.o � "{Top}"Python:atof.c
	{CC} "{Top}"Python:atof.c -o "{Objs}"atof.c.o -s atof.c {CFlags}

"{Objs}"strtod.c.o � "{Top}"Python:strtod.c
	{CC} "{Top}"Python:strtod.c -o "{Objs}"strtod.c.o -s strtod.c {CFlags}

"{Objs}"fmod.c.o � "{Top}"Python:fmod.c
	{CC} "{Top}"Python:fmod.c -o "{Objs}"fmod.c.o -s fmod.c {CFlags}
