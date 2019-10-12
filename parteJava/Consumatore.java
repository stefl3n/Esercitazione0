import java.io.FileDescriptor;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Consumatore {
	
	public static void main(String[] args) throws IOException {
		
		String word = args[0];
		int buff;
		String buffer;
		FileReader in = null;
		buffer="";
		try {
		if(args.length==1) {
		
			in = new FileReader(FileDescriptor.in);
		
		}
		else if(args.length==2)
		{
			in = new FileReader(args[1]);
			
		}
		else
		{
			System.out.println("Utilizzo: consumatore <filterString> <inputFilename>  || consumatore <filterString>" );
		}
		
		
		while((buff=in.read())!= -1) {
			
				if(word.contains(""+(char)buff+"")) 
				{
					;
				}
				else {
				buffer=buffer+(char)buff;
				
				}
			
		}
		System.out.println(buffer);
		in.close();
		}
		catch(IOException e)
		{
			e.printStackTrace();
			System.exit(1);
		}

	}
	
}
