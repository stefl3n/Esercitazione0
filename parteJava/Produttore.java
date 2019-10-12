import java.io.*;

public class Produttore {
	public static void main(String args[]) {
		
		BufferedReader in;
		FileWriter out;
		int c;
		if (
				args.length!= 1){
				System.out.println("Utilizzo: produttore <inputFilename>");
				System.exit(0);
				}
		
		in = new BufferedReader(new InputStreamReader(System.in));
		try {
		out = new FileWriter(args[0]);
		
	
		
		do {
			System.out.println("Inserisci riga");
			
			while((char)(c = in.read()) != '\n' && c != -1) {
				
				out.write(c);
				
			}
			out.write("\n");
		}while(c != -1);
		out.close();
		}catch(IOException e)
		{
			e.printStackTrace();
			System.exit(1);
		}
		
	}

}
