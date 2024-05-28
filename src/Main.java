import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main {
    public static void main(String[] args) throws IOException {
        File file = new File("/Users/christineswann/Documents/GitHub/JavaCppTest1/text/Data1.txt");


    //Reading:
        String line2 = Files.readAllLines(Paths.get(file.getAbsolutePath())).get(2); /*Read specific lines */
        System.out.println(line2);


    //Writning:
    
        FileInputStream fis = new FileInputStream(file);
        InputStreamReader isr = new InputStreamReader(fis);
        BufferedReader br = new BufferedReader(isr);
        String line = br.readLine();
        FileWriter fr = new FileWriter(file, true);
        BufferedWriter bw = new BufferedWriter(fr);
        
        if((line = br.readLine()) != null || br.readLine() != ""){bw.newLine();} /* ADding new lines */

        String line4 = Files.readAllLines(Paths.get(file.getAbsolutePath())).get(4);
        line4.trim();
        PrintWriter pr = new PrintWriter(bw);
        pr.println("data");
        
        pr.close();
        bw.close();
        br.close();


    }
}