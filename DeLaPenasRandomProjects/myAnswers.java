/**
 * @(#)myAnswers.java
 *
 *  This program uses File I/O to read in text documents built by students.
 *  These messages are mapped to Unicode values, and then translated to an
 *  alternate number base.  This program decodes these messages.
 *
 *  Note: Unprintable / unrecognizable Unicode characters were assigned the value 'X'
 *
 *
 *  All of the File I/O handling and output production is handled by the main method.
 *	
 * @author Lyra Wolves
 * @version 1.25 2015/9/12
 */
import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Comparator;

class myAnswers
{
	public static void main(String[] args) throws IOException //necessary becausee of creation of FileOutputStream, specific exception is FileNotFoundException
	{
		//Relative paths are fine
		ArrayList<String> answers = new ArrayList<String>(7);
		System.out.print("Enter file path:: ");
		Scanner i = new Scanner(System.in);
		File inputFile = new File(i.nextLine());
		System.out.print("Enter path to output file:: ");
		System.setOut(new java.io.PrintStream(new java.io.FileOutputStream(i.nextLine()),true)); //creates file object denoted by path from user, creates ouput stream, then sets to system.out
		if(inputFile.isDirectory()) //allows parsing of multiple files in one run
		{
			File dir[] = inputFile.listFiles();
			java.util.Arrays.sort(dir,new Comparator<File>(){
			public int compare(File f1, File f2) //used to sort files so they show up in order
			{
				return f1.getName().compareTo(f2.getName()); //compares by file name
			}});
			for(File input: dir)
			{
				System.out.println("File:: " + input.getName());
				if(generateAnswers(input, answers) != 0) //Checks if generateAnswers returned normally
					System.out.println("ERROR:: Could not read file.");		
				else
					for(String ans:answers)
						System.out.println(ans);
				System.out.println("DONE");
			}
		}
		else
		{
			System.out.println("File:: "+inputFile.getName());
			if(generateAnswers(inputFile, answers) != 0)
				System.out.println("ERROR:: Could not read file.");		
			else
				for(String ans:answers)
					System.out.println(ans);
			System.out.println("DONE");
		}
	}
	//generates answers and stores in answers array list
	static int generateAnswers(File inputFile, ArrayList<String> answers)
	{
		byte radix = 2; //the lonely type -->also the size of a char in C
		try //there is no need for seperate try catch blocks since the only indication of an error is a "1" for the return value
		{
			Scanner scan = new Scanner(inputFile);
			int sz = scan.nextInt();
			scan.nextLine();
			String orgMsg[] = new String[sz];
			for(int cnt = 0;cnt<sz;cnt++)
				orgMsg[cnt] = scan.nextLine();
			scan.close();
			answers.removeAll(answers); //this looks like part of a very interesting joke
			while(radix<17)
			{
				String temp = outMsg(orgMsg,radix,sz);
				if(temp != null)
					answers.add("Base "+radix+":: "+temp);
				radix++;
			}
			if(answers.isEmpty())
				answers.add("No valid strings found.");
			return 0;
		}
		catch(Exception e) //Not the best way to handle format errors...
		{
			return 1; //indicates failure
		}
	}
	//attempts to convert from base x to base 10
	//on error returns 0, used in outMsg function to reduce number of runs
	static long radixToTen(String num, int radix)
	{	
		try
		{
			long ans = Long.parseLong(num.substring(num.length()-1).trim(),radix);
			long power = 1;
			for(int y=num.length()-2;y>-1;y--)
			{
				power*=radix;
				ans+=Long.parseLong(num.substring(y,y+1).trim(),radix)*power;
			}
			return ans;
		}
		catch(NumberFormatException e)
		{
			return 0;
		}
	}
	static String outMsg(String orgMsg[], int radix, int sz)
	{
		/*----->Assumes full use of UNICODE is allowed
		*MAX digits in num necessary in base 2:: 32 -->MIN digits to get non control character in base 2:: 6
		*MAX digits in num necessary in base 3:: 21 -->MIN digits to get non control character in base 3:: 4
		*MAX digits in num necessary in base 4:: 16 -->MIN digits to get non control character in base 4:: 3
		*MAX digits in num necessary in base 5:: 14 -->MIN digits to get non control character in base 5:: 3
		*MAX digits in num necessary in base 6:: 13 -->MIN digits to get non control character in base 6:: 2
		*MAX digits in num necessary in base 7:: 12 -->MIN digits to get non control character in base 7:: 2
		*MAX digits in num necessary in base 8:: 11 -->MIN digits to get non control character in base 8:: 2
		*MAX digits in num necessary in base 9:: 11 -->MIN digits to get non control character in base 9:: 2
		*MAX digits in num necessary in base 10:: 10 -->MIN digits to get non control character in base 10:: 2
		*MAX digits in num necessary in base 11:: 10 -->MIN digits to get non control character in base 11:: 2
		*MAX digits in num necessary in base 12:: 9 -->MIN digits to get non control character in base 12:: 2
		*MAX digits in num necessary in base 13:: 9 -->MIN digits to get non control character in base 13:: 2
		*MAX digits in num necessary in base 14:: 9 -->MIN digits to get non control character in base 14:: 2
		*MAX digits in num necessary in base 15:: 9 -->MIN digits to get non control character in base 15:: 2
		*MAX digits in num necessary in base 16:: 8 -->MIN digits to get non control character in base 16:: 2
		*<----------Maybe later the other control characters could be counted out too
		*<----------If you need more than the above you are either
		*<----------using a different standard, or you have a problem...
		*<----------Or I do, but that's irrelevant, it should be fixed
		*/
		String output = "";
		for(int x=0;x<sz;x++)
		{
			long temp = (radixToTen(orgMsg[x],radix));
			//this checks to make sure all characters all valid UNICODE before adding to string
			if(temp<32 || temp>65535) //32 is first non control character. 65535, current highest defined unicode code point
				return null; //stops parsing as soon as an invalid value is found, reduces number of computations
			output+=(char)temp; //currently char must be within basic multilingual plain (does not support supplementary characters)
		}
		return output;
	}
}
