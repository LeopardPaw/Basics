Author: James De la Pena
9/12/2015
This is my version of the "Can Corbin Crack It" solution code.
I also started writing "javadoc" style comments, so I can use the "javadoc" tool to
auto-generate APIs, but I got lazy with the accessors and modifiers.

- - Notes to Corbin Adamson ::

This is my version of the "Can Corbin Crack It" solution code.  It is not as
in-depth with File I/O as it could be.  I was impressed by the depth of File I/O in
the code your provided me, which searched through directories, redirected
standard output to an output file (which didn't even need to previously exist,
AND the user could custom-name!)  Very elegant work!  Kudos.

Compile and Run
"BaseConverter.java" (the runner/driver file) to see the output of my program.
And yes, it is set to output to the console!

All text files were re-named "messageN.txt", where N is an integer in the range [0,18]
and stored in a directory named "data", located in the current working directory
(same directory the source code compiles/runs from).

message0.txt is my example file.

All files have been cleaned up, as far as formatting (or at least the best I could do).
I took note of students with formatting issues.  (points off)
Wanted to provide you with all the data files and see if you get the same results running
them as I did.

Take a note of how "OOP-ified" the code I have provided here is.
I could have even taken many of the procedures performed in the main method,
and re-written them as object methods (non-static methods) in "BasedNumber.java".

It's Java.  Not C.  Take advantage of objects!!
It's also standard convention to limit the number of lines in the main method / the number
of lines in the "runner" file.  Basically, the OBJECT should be doing pretty much ALL the work.

Don't get me wrong - I enjoyed your code very much; it just reminded me a little
too much of C.  You killed AP, which is awesome, but if you're still looking to be 
a UIL state champ, the standard language is still Java!!
C can be better/easier with File I/O than Java.
Remember, in the industry / field... we pick the right language for the right job!
(But yes, for now... learn as much as Java as possible for UIL!)

But more than that, study all the reasons WHY a particular language would be a
"good choice" for certain tasks.
For example, PERL is actually an acronym for "Practical Extraction and Reporting Language",
because it is excellent at dealing with lists; thus, many programs use PERL scripts for
large File I/O tasks such as building / modifying / moving entire directory trees from one
location to another.  It's Practical for Extracting data, and Reporting it back.  Lots of piping.
If you know basic UNIX shell navigation, PERL is definitely a language worth studying.
I believe I have a book... somewhere.
If I remember correctly, Python can be used in a similar way (it's great with lists)
and may be replacing PERL, in some regards.  They're both good scripting languages.

As far as my code, I tried to keep it fairly simple.
I could have done more with try-catch blocks and exceptions, but I didn't feel like it.  :)