#CMPSC311P1
#Liam Geoghan ljg5222
#Vedant Tiwari vzt5060

(i) Descriptions:

SHELL
The script opens by getting the start time and then checks for the appropriate amount of
arguments (four). It also checks that each argument is entered with the correct .txt
extension. First, double hyphens are removed because there was a problem in Hamlet 
specifically where words were separated by hyphens instead of whitespace. Next, the actual 
process begins by using gawk to print each individual word to its own line. Next, two temp
files are created, one containing only digits and the other containing only letters. The 
letters are also formatted to only be lowercase and the special characters are removed.
Finally, both lists are sorted numerically/alphabetically, blank lines are removed, and
the two text files are counted using the uniq function before being concatenated into the 
designated output file. The temp files are deleted and the end time is recorded in order 
to calculate the final runtime and output it to a separate file.

C
The script opens with appropriate library imports, function declarations, and the struct
definition. <stdio.h> is included for obvious reasons as it contains most of the c 
functionality. <string.h> is included for the convertToNormal function so the words can be
converted to all lowercase. <time.h> and <sys/time.h> are included for the gettimeofday
function so we can get the runtime of the program. <stdlib.h> is included for malloc so we
can dynamically allocate memory for the linked list. The actual program begins by getting
the start time and checking to make sure there are four arguments. Then the input file is 
open and scanned until the end so that a linked list is created with each element getting 
a single word. Next, a merge sort (with standard function) occurs to put the words in 
order. The linked list is then iterated through and words are compared so that duplicates
add to the count for each unique word. Finally, the designated output file that was opened
is written to with the different words and their counts, and the runtime file is also 
created by getting the time of day again and outputting the difference.

(ii) Comparison:

Writing the shell script was more difficult to start off with because it was a brand new
format compared to the coding we've done in previous classes. However, once we got down
the syntax (via much Googling) we actually enjoyed it much more than the C script coding.
The shell script coding seems less readable, but it is succinct and works fine. In the
long run, the C script ended up proving more difficult to code because the linked list
format was confusing, but with that complexity came a lot more efficiency.

(iii) Difficulties:

There are certain words during testing that accidentally got concatenated such as 
"you--if" becoming "youif" since there wasn't whitespace between them, and we managed to 
fix that for the shell script but there are still some errors in the c script. Also, there
is a segfault for the Arabian Nights textfile, that we can't seem to figure out. It may
have to do with the amount of whitespace and empty (maybe null) lines in the text, because
we're pretty sure it isn't the malloc since we didn't specify an actual size for that.

(iv) Performance Results:

SHELL 
Average:
Standard Deviation:

C
Average:
Standard Deviation: