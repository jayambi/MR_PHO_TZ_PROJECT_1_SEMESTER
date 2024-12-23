
#### Start of system configuration section. ####

VERSION := 2.00
CC      := gcc -O
CFLAGS  := -Wall -c
LDFLAGS := -g
LIBS = -lm
RM      := rm

#### End of system configuration section. ####

.PHONY: all sort doc print clean

# TARGET.exe
TARGET     = Pho_Mr_helper

# Path for .c , .h and .o Files 
SRC_DIR = ./src/
OBJ_DIR = ./obj/
DOX_DIR = ./doc/doxygen/

# Files to compile
c_FILES := $(wildcard $(SRC_DIR)/*.c)
o_FILES := $(addprefix obj/,$(notdir $(c_FILES:.c=.o)))

#link all .o files
$(TARGET): $(o_FILES)
	@echo [CC] link: $<
	@$(CC) $(LDFLAGS) -o $@ $^

#compile all .c Files 
obj/%.o: src/%.c
	@echo [CC] compile: $<
	@$(CC) $(CFLAGS) -o $@ $<
	
#run TARGET.exe
run:
	$(TARGET)
	
#create folders and sort files
sort:
	@-mkdir src obj
	@-mv *.c *.h src
	@-mv *.o obj
	
#create folde "doc" then run doxygen
doc:
	@echo need to start RunDoxy.bat manually
#	@-mkdir doc
#	@call $(DOX_DIR)RunDoxy.bat
		
# Clean all the object files and the binary
clean:   
	@echo "[Cleaning]"
	@$(RM) -rfv $(OBJ_DIR)*
	@$(RM) -rfv $(TARGET).exe

help:
	@echo -e Version:   ' \t ' $(VERSION)
	@echo -e CC:       ' \t \t '  $(CC)
	@echo -e CFLAGS:   ' \t ' $(CFLAGS)
	@echo -e LDFLAGS:  ' \t ' $(LDFLAGS) ' \n ' 
	@echo    commands:
	@echo -e sort  ' \t \t ' sort files
	@echo -e run   ' \t \t ' run $(TARGET).exe
	@echo -e doc   ' \t \t ' run doxygen
	@echo -e clean ' \t \t ' clean all the .o
	@echo -e type make -help for more
	
		