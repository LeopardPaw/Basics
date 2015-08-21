/**
 * @(#)BasedNumber.java
 *
 *  This program uses File I/O to read in text documents built by students.
 *  These messages are mapped to Unicode values, and then translated to an
 *  alternate number base.  This program decodes these messages.
 *
 *  Note: Unprintable / unrecognizable Unicode characters were assigned the value 'X'
 *
 *	This object file defines instance variables associated with the representation
 *  of a number (represented as a String of characters), in an integer base in the range [2,16]
 *  It has methods which return the base-10 value as well as the associated ASCII character
 *
 * @author James De la Pena
 * @version 1.20 2015/9/12
 */

import static java.lang.System.*;

public class BasedNumber 
{
	/** 
	 *	Fields / Instance Variables / Private Data
	 */
	private int myBase;
	private String myValue;
	private int myBase10Value;

	/**  
	 *	Default Constructor: creates a new instance of a BasedNumber.  
	 *  Assumes a base of 10, and String representation of "0"
	 */
    public BasedNumber() 
    {
    	myBase = 10;
    	myValue = "0";
    	myBase10Value = Integer.parseInt(myValue);
    }
    
    /** 
     *	Constructor.  Takes in a String representation of a number and its base.
     *  Note: This initializes "myBase10Value" to 0.  It does not automatically call
     *  the calculateBase10Value() method. 
     *
     *  @param value a String representation of a BasedNumber, using chars [0-9][A-F]
     *  @param base the integer base of this particular BasedNumber
	 */
    public BasedNumber(String value, int base) 
    {
    	myBase = base;
    	myValue = value;
    	myBase10Value = 0;
    }
    
    // Accessors: straight-forward; not given javadoc-style comments here
    public int getBase()	{	return myBase;	}
    public String getValue()	{	return myValue;	}
    public int base10Value()	{	return myBase10Value;	}
    
    // Modifiers: straight-forward; not given javadoc-style comments here
    public void setBase(int b)	{	myBase = b;	}
    public void setValue(String v)	{	myValue = v;	}
    
    /**
     *  Traverses a loop to calculate a base-10 integer, based on the String representation
     *  and the integer base.  Note: This method does NOT return a value.  It DOES modify the
     *  value of the instance variable "myBase10Value".
     */
    public void calculateBase10Value()
    {
    	int result = 0;
    	String s = myValue;
    	for(int k = myValue.length()-1; k >= 0; k--)
    	{
    		int a;
    		if(s.charAt(k) >= 'A')
    			a = letterToValue(""+s.charAt(k));
    		else
    			a = Integer.parseInt(""+s.charAt(k));
    		int placeValue = (int)(Math.pow(myBase, (myValue.length()-(k+1))));
    		result += (a * placeValue);
    	}
    	myBase10Value = result;
    }
    
    /**
     *  This method simply returns this BasedNumber, converted to its base-10 value, and type-casted to type "char",
     *  which represents the Unicode character associated with that value.
     *
     *	@return the char which maps with the value of this BasedNumber (based on the Unicode system)
     */
    public char myASCIIChar()
    {
    	return ((char)myBase10Value);
    }
    
    /** 
     *	Helper method: Handles conversion values for Bases 11-16.  Declared private since it
     *  need not be used outside of this particular class.
     *  Updated in v1.20 to ignore case sensitivity.
     *
     *  @param s a single-character String in the range [A-F], representing a quantity of ten or larger
     *	@return an int value, using conversions A=10,B=11,C=12,etc... such as used in Hexadecimal.
     *  @return the integer Unicode value for the letter 'X' for any input letter besides [A-F]
     */
    private int letterToValue(String s)
    {
    	if(s.equalsIgnoreCase("A"))		return 10;
    	else if(s.equalsIgnoreCase("B"))	return 11;
   		else if(s.equalsIgnoreCase("C"))	return 12;
   		else if(s.equalsIgnoreCase("D"))	return 13;
   		else if(s.equalsIgnoreCase("E"))	return 14;
   		else if(s.equalsIgnoreCase("F"))	return 15;
   		else					return ((int)'X');
    }
}