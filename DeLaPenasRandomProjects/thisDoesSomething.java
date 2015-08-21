import java.io.File;
import java.util.HashMap;
class thisDoesSomething
{
	private File msg;
	private Scanner scan;
	private HashTable<String,long> compressionTable;
	public thisDoesSomething()
	{
		setFile(null);
		compressionTable = new HashTable<String,long>();
	}
	public thisDoesSomething(String str)
	{
		setFile(new File(str));
		compressionTable = new HashTable<String,long>();
	}
	public thisDoesSomething(File f)
	{
		setFile(f);
		compressionTable = new HashTable<String,long>();
	}
	
}