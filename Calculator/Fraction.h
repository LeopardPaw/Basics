struct Fraction
{
     	int numerator;
  	int denominator;
};
min(int x, int y) 
{ 	
	return (x<=y)?x:y; 
} 
findGCF(int x,int y,int k) //finds greatest common factor) 
{
	if((x%k==0) && (y%k==0))
        	return k;
	return findGCF(x,y,k-1);
}
void reduce(struct Fraction *x) //reduces fraction
{
	int min(int x, int y);
	int gcf = findGCF(x->numerator,x->denominator,min(x->numerator,x->denominator));
	x->numerator=x->numerator/gcf;
	x->denominator=x->denominator/gcf;
	if(x->denominator<0)
	{
        	x->numerator*=-1;
        	x->denominator*=-1;
    	}
}
float decimalValue(struct Fraction x)
{
	if(x.denominator==0)
		return -0.0;
	return ((float)x.numerator)/x.denominator;
}
struct Fraction divide(struct Fraction x, struct Fraction y)
{
	void reduce(struct Fraction *x);
	struct Fraction ans;
	ans.numerator=(x.numerator * y.denominator);
	ans.denominator=(x.denominator * y.numerator);
	reduce(&ans);
	return ans;
}
struct Fraction multiply(struct Fraction x, struct Fraction y)
{
	void reduce(struct Fraction *x);
	struct Fraction ans;
	ans.numerator=(x.numerator * y.numerator);
	ans.denominator=(x.denominator * y.denominator);
	reduce(&ans);
	return ans;
}
struct Fraction reciprocal(struct Fraction x)
{
	void reduce(struct Fraction *x);
	struct Fraction ans;
	ans.numerator=x.denominator;
	ans.denominator=x.numerator;
	reduce(&ans);
	return ans;
}
struct Fraction add(struct Fraction x, struct Fraction y)
{
	void reduce(struct Fraction *x);
	x.numerator = (x.numerator*y.denominator) + (y.numerator*x.denominator);
	x.denominator = x.denominator*y.denominator;
	reduce(&x);
	return x;
}
struct Fraction subtract(struct Fraction x, struct Fraction y)
{
	void reduce(struct Fraction *x);
	x.numerator = (x.numerator*y.denominator) - (y.numerator*x.denominator);
	x.denominator = x.denominator*y.denominator;
	reduce(&x);
	return x;
}
