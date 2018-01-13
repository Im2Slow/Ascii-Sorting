##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=asciiSorting
ConfigurationName      :=Debug
WorkspacePath          :=/home/adrien/Documents/ProgC
ProjectPath            :=/home/adrien/Documents/ProgC/asciiSorting
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=adrien
Date                   :=13/01/18
CodeLitePath           :=/home/adrien/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="asciiSorting.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/user.c$(ObjectSuffix) $(IntermediateDirectory)/vector.c$(ObjectSuffix) $(IntermediateDirectory)/array.c$(ObjectSuffix) $(IntermediateDirectory)/main.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/user.c$(ObjectSuffix): user.c $(IntermediateDirectory)/user.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/adrien/Documents/ProgC/asciiSorting/user.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/user.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/user.c$(DependSuffix): user.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/user.c$(ObjectSuffix) -MF$(IntermediateDirectory)/user.c$(DependSuffix) -MM user.c

$(IntermediateDirectory)/user.c$(PreprocessSuffix): user.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/user.c$(PreprocessSuffix) user.c

$(IntermediateDirectory)/vector.c$(ObjectSuffix): vector.c $(IntermediateDirectory)/vector.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/adrien/Documents/ProgC/asciiSorting/vector.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vector.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vector.c$(DependSuffix): vector.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/vector.c$(ObjectSuffix) -MF$(IntermediateDirectory)/vector.c$(DependSuffix) -MM vector.c

$(IntermediateDirectory)/vector.c$(PreprocessSuffix): vector.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vector.c$(PreprocessSuffix) vector.c

$(IntermediateDirectory)/array.c$(ObjectSuffix): array.c $(IntermediateDirectory)/array.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/adrien/Documents/ProgC/asciiSorting/array.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/array.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/array.c$(DependSuffix): array.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/array.c$(ObjectSuffix) -MF$(IntermediateDirectory)/array.c$(DependSuffix) -MM array.c

$(IntermediateDirectory)/array.c$(PreprocessSuffix): array.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/array.c$(PreprocessSuffix) array.c

$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/adrien/Documents/ProgC/asciiSorting/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


