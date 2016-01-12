/////////////////////////////
// DO NOT SUBMIT THIS FILE //
/////////////////////////////

import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;
import java.util.HashSet;


public class ArtLib2 {
	private static final int CODE_SIZE_MISMATCH = -1;
	private static final int CODE_NO_TOUR = -2;
	private static final int CODE_FIRST_COLOR_NOT_ONE = -3;
	private static final int CODE_NO_CONNECTION = -4;
	private static final int CODE_TOO_LONG_DIST = -5;
	private static final int CODE_TOUR_EXCESS = -6;
	
	private static int checkSolution(int n, int m, Connexion[] scheme, int[] teamColors, int[] teamTour) {
		return 0;
	}

	public static void main(String args[]) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		
		int numOfCases;
		int n, m;
		numOfCases = in.nextInt();
		for (int tt = 0; tt < numOfCases; tt++) {
			n = in.nextInt();
			m = in.nextInt();
			Connexion[] scheme = new Connexion[m];
			for (int i = 0; i < m; i++) {
				int a, b;
				a = in.nextInt();
				b = in.nextInt();
				scheme[i] = new Connexion(a, b);
			}
			
			Pair<int[], int[]> teamAnswer = Art2.draw_literate_painting(n, m, scheme);
			int checkResult = checkSolution(n, m, scheme, teamAnswer.f, teamAnswer.s);
			
			if (checkResult != 0) {
				out.printf ("INCORRECT - Test case %d: ", tt+1);
				if (checkResult == CODE_SIZE_MISMATCH)
					out.printf("size mismatch, received %d, expected %d", teamAnswer.f.length, n);
				else if (checkResult == CODE_NO_TOUR)
					out.printf("received empty tour");
				else if (checkResult == CODE_FIRST_COLOR_NOT_ONE)
					out.printf("color of the first vertex in tour is not 1");
				else if (checkResult == CODE_NO_CONNECTION)
					out.printf("tour includes nonexistent connection");
				else if (checkResult == CODE_TOO_LONG_DIST)
					out.printf("distance between some pair of colors is bigger than 3 (tour is illiteral)");
				else if (checkResult == CODE_TOUR_EXCESS)
					out.printf("tour is too long, should be shorter");
				else if (checkResult > 0)
					out.printf("didn't find color %d", checkResult % n);
				else
					out.printf("unknown code error");
				out.printf("\n");
				out.close();
				System.exit(0);
			}
		}
		out.printf("COULD BE CORRECT\n");
		out.close();
	}
}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}
}

class Connexion {
	public int a;
	public int b;
	
	Connexion(int a_value, int b_value) {
		a = a_value; 
		b = b_value; 
	}
}
class Pair<F, S> {         
	public final F f;
	public final S s;

	public Pair(F f, S s) {         
		this.f = f;
		this.s = s;
	}
}
