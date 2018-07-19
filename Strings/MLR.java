import java.io.*;
import java.lang.*;
public class MLR{
	public MLR(){
		try{
			BufferedReader br = new BufferedReader( new InputStreamReader(System.in) );
			String str = br.readLine();
			String res = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
			for(int i=0;i<str.length();i++){
				StringBuilder sb = new StringBuilder();	
				sb.append( str.substring(0,i+1) );
				String aux = sb.reverse().toString();
				for(int j=i+1;j<str.length()-1;j++){
					sb.setLength(0);
					sb.append( str.substring(i+1,j+1) );
					String aux2=aux+sb.reverse().toString();

					sb.setLength(0);
					sb.append( str.substring(j+1,str.length()));
					aux2+=sb.reverse().toString();
					if( aux2.compareTo(res) < 0 )
						res = aux2;
				}
			}
			System.out.println(res);	
		}catch(Exception e){}
	}
	public static void main(String args[]){
		new MLR();
	}	
}