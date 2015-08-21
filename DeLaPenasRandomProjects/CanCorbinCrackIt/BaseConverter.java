/**
 * @(#)BaseConverter.java
 *
 *  This program uses File I/O to read in text documents built by students.
 *  These messages are mapped to Unicode values, and then translated to an
 *  alternate number base.  This program decodes these messages.
 *
 *  Note: Unprintable / unrecognizable Unicode characters were assigned the value 'X'
 *
 *  This is the runner/driver file, which contains only the main method.
 *  All of the File I/O handling and output production is handled by the main method.
 *	
 * @author James De la Pena
 * @version 1.20 2015/9/12
 */

import static java.lang.System.*;
import java.util.Scanner;
import java.io.File;
import java.io.IOException;

public class BaseConverter
{
	public static void main(String[] args) throws IOException
	{
		Scanner s;
		// The most outer loop is used to loop through each text file (hard-coded from [0-18])
		for(int i = 0; i <= 18; i++)
		{
			out.print("----- NEW FILE -----\t");
			s = new Scanner(new File("data\\message"+i+".txt"));
			out.println("File name: message"+i+".txt");
			int numTimes = s.nextInt();
			BasedNumber[] nums = new BasedNumber[numTimes];
        	s.nextLine();
        	
        	for(int k = 0; k < numTimes; k++)
        		nums[k] = new BasedNumber(s.nextLine(), 2);
        	
        	for(int x = 2; x <= 16; x++)
        	{
        		String testString = new String("");;  // this will build the message into a string
				String compareString = new String("");	// this fills a string of the same length with all 'X's for comparison.
        		out.print("BASE " + x + " : ");
        		for(int j = 0; j < nums.length; j++)
        		{
        			nums[j].setBase(x);
        			nums[j].calculateBase10Value();
        			char current = nums[j].myASCIIChar();
        			
        			if(current < 32)	//newly-added to address annoying non-printable chars
        				current = 'X';
        			testString += ""+current;
        			compareString += "X";
        			
        			out.print(""+current);          		
        		}
        		
        		// For debugging :: commented out here (v1.20)
        			//out.println("\n testString : " + testString);
        			//out.println("\n compareString : " + compareString);
        		
        		// Get rid of leading/trailing whitespace
        		testString = testString.trim();
        		compareString = compareString.trim();
        		
        		// The following algorithm deletes the previous line of text which was
        		// printed out, if and only if the message translated into a series consisting of
        		// nothing but 'X' characters. (These represent unprintable chars or an 
        		// error in calculation).
        		// This minor tweak makes it so that many "BASE 2" and "BASE 3" conversions are not 
        		// printed out, since they are "obviously" not what was intended by the message writer. 
        		if(testString.equalsIgnoreCase(compareString))
        		{
        			for(int h = 0; h < testString.length() + 8; h++)
        				out.print("\b ");	// this loop of "\b" chars deletes the previous line
        		    out.print("\r");	// performs a carriage return
        		}
				else
					out.print("\n");	// performs a newline command
       	 	}
       	 	out.println("-- DONE. NO ERRORS.");
		} 
    }
}
