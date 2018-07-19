import java.util.HashMap;
import java.util.Map;
import java.util.Iterator;
import java.util.Set;
import java.io.*;
import java.lang.*;

public class MLR{
	private static int MAXN = 432;
	private short numbers[][] = new short[MAXN][MAXN];
	private short[] primos = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,
				83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,
				173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,
				263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,
				359,367,373,379,383,389,397,401,409,419,421,431};
	public MLR(){
		try{
			PreCalculo();
			BufferedReader br = new BufferedReader( new InputStreamReader(System.in) );
			String str = "";
			while((str=br.readLine())!=null){
				String[] spl = str.split(" ");
				short n = Short.parseShort(spl[0]);
				short k = Short.parseShort(spl[1]);
				System.out.println( Divisor(n,k) );
			}
		}catch(Exception e){
		}
	}

	private void PreCalculo(){
		for(int i=2;i<MAXN;i++){
		int aux = i;//COPY TO GET ALL DIVISORS FOR THIS NUMBER
		int j = 0;//PRIMOS INDEX
		while( aux != 1){
			int div = 0;//COUNTER FOR POW FOR THE CURRENT PRIME
			if(aux%primos[j] == 0)
				while(aux%primos[j] == 0){
					div++;aux/=primos[j];
				}
			numbers[i][j]+=div;
			j++;
		}
		for(j=0;j<primos.length;j++)
			numbers[i][j]+=numbers[i-1][j];
		}	
	}
	private long Divisor(short n, short  k){
		long res = 1;
		for(int i=0;i<=primos.length;i++)
			res*=(numbers[n][i]-numbers[k][i]-numbers[n-k][i])+1;
		return res;
	}
	public static void main(String args[]){
		new MLR();
	}	
}