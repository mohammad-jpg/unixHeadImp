# unixHeadImp
Assignment 1 Details and Submission
The Unix utilities head and tail output the first and last parts of files respectively. Your assignment is to implement your own version of these utilities in C.

You will submit your code to file submission.

1. Implement both head and tail, even and odd line listing.

2. You should work independently, you may consult with each other but submit code that is entirely yours. You are free to use any code from lectures and labs. Feel free to read the source code of GNU head and tail but please don’t submit code based directly on this.

3. Submit a single .c file. Name the file exactly assign1-XXX.c where XXX is your student number.

4. In the comment block at the top, explain concisely what the program does and include your name, student number and email address.

5. Note in the comment block how well you completed task (eg. Works completely; or x and y work, but z does not).

Use getopt to accept the following optional parameters:

{ head | tail } [OPTION ] . . . [ FILE ]

Print the first | last 10 lines of FILE to standard output .

If no FILE read standard input.

Options :

-n K output the first|last K lines

-V Output version info: Your name, email, student number.

-h display and exit ( something like this )

-e print even lines.

-o print odd lines.

The odd and even line printing may be a little bazaar and generally useless, but it is there to test your programming. If -n 20, then your program should output 20 lines (eg. half of the first|last 40 lines). Number the first line of the file as 1 when calculating odd and even.

Check-list:

• Submit the code to assignment submission.

-Ensure you press “Submit all and finish” before the deadline.

• Name your file as specified.

• Include a note on your progress.

• Make good use of lecture notes and labs.
