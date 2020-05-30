htags: findtags.c htags.c
	gcc -o htags -Wall findtags.c htags.c

test: sample_test hello_test

sample_test: htags
	./htags ./A4Data/Sample.html > sample_test.results
	./TestPassed.sh sample_test.result ./A4Data/sample_test.expected

hello_test: htags
	./htags ./A4Data/HelloWorld.html > hello_test.results
	./TestPassed.sh hello_test.result ./A4Data/hello_test.expected
