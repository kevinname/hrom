CPUPATH         = $(PROJ_PATH)/start

CPUSRC = $(CPUPATH)/vector_32ivic.S \
         $(CPUPATH)/start.S 

CPUINC = -I$(CPUPATH) \
         -I$(CPUPATH)/CPU_DEF



