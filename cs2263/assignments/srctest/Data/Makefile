# compile with gcc
COMPILER = gcc

# The C flags to pass to gcc
C_FLAGS = -std=gnu99 -Wall -Wextra

# link our .o files to make an executable
htmltags: htmltags.o htmllib.o
	$(COMPILER) $(C_FLAGS) -o htmltags htmltags.o htmllib.o

htmltags.o: htmltags.c
	$(COMPILER) $(C_FLAGS) -c htmltags.c

htmllib.o: htmllib.c
	$(COMPILER) $(C_FLAGS) -c htmllib.c

#link the counting test
tagCount: tagCount.o htmllib.o

tagCount.o: tagCount.c
	$(COMPILER) $(C_FLAGS) -c tagCount.c

##################################################################
# Test Cases
test: sample_test form_test form-al_test HelloWorld_test

sample_test: htmltags
	./htmltags < Data/Sample.html > sample_test.result 
	./TestPassed.sh sample_test.result Data/sample_test.expected

form_test: htmltags
	./htmltags < Data/form.html > form_test.result 
	./TestPassed.sh form_test.result Data/form_test.expected

form-al_test: htmltags
	./htmltags < Data/form-al.html > form-al_test.result 
	./TestPassed.sh form-al_test.result Data/form-al_test.expected

HelloWorld_test: htmltags
	./htmltags < Data/HelloWorld.html > HelloWorld_test.result 
	./TestPassed.sh HelloWorld_test.result Data/HelloWorld_test.expected

HelloWorld_test: htmltags
	./htmltags < Data/HelloWorld.html > HelloWorld_test.result 
	./TestPassed.sh HelloWorld_test.result Data/HelloWorld_test.expected

tagCount_test: tagCount
	./tagCount > tagCount_text.result
	./TestPassed.sh tagCount_text.result Data/tagCount_text.expected