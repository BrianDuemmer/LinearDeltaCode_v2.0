# invoke SourceDir generated makefile for main.pem4f
main.pem4f: .libraries,main.pem4f
.libraries,main.pem4f: package/cfg/main_pem4f.xdl
	$(MAKE) -f C:\CodeDirectory\CCS\LinearDeltaCode_v2.0/src/makefile.libs

clean::
	$(MAKE) -f C:\CodeDirectory\CCS\LinearDeltaCode_v2.0/src/makefile.libs clean

