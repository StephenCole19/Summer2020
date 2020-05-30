# compile with gcc
COMPILER = gcc

# The C flags to pass to gcc
C_FLAGS = -std=gnu99 -Wall -Wextra

#Linking the main html tags program
htmltags: htmltags.o htmllib.o
	$(COMPILER) $(C_FLAGS) -o htmltags htmltags.o htmllib.o

htmltags.o: htmltags.c
	$(COMPILER) $(C_FLAGS) -c htmltags.c

htmllib.o: htmllib.c
	$(COMPILER) $(C_FLAGS) -c htmllib.c

#Linking the comments test program
comments: comments.o htmllib.o
	$(COMPILER) $(C_FLAGS) -o comments comments.o htmllib.o

comments.o: comments.c
	$(COMPILER) $(C_FLAGS) -c comments.c
	
#link the counting test
tagCount: tagCount.o htmllib.o

tagCount.o: tagCount.c
	$(COMPILER) $(C_FLAGS) -c tagCount.c

##################################################################
# HTML Tags Test Cases
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

##################################################################
# Comments Test Cases
comments_test: comments
	./comments < Data/Sample.html > comments_test.result 
	./TestPassed.sh comments_test.result Data/comments_test.expected

##################################################################
# tag count Test Cases
tagCount_test: tagCount
	./tagCount > tagCount_test.result
	./TestPassed.sh tagCount_test.result Data/tagCount_test.expected
