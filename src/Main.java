import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main {
    public static void main(String[] args) throws IOException {
        File file = new File("/Users/christineswann/Documents/GitHub/JavaCppTest1/text/Data1.txt");

//Writning:
            
            FileWriter fr = new FileWriter(file, true);
            BufferedWriter bw = new BufferedWriter(fr);
            bw.write("Writing from the java file!!!!");
            bw.close();
//Reading:
        FileInputStream fis = new FileInputStream(file);
        InputStreamReader isr = new InputStreamReader(fis);
        BufferedReader br = new BufferedReader(isr);

        String line;
        /*one line:
        line = br.readLine();
        System.out.println(line);*/
        /* ALL THE txt content:
        while((line = br.readLine()) != null){
            //process the line
            System.out.println(line);
        }/* */
        for(int x=0; x<2; x++){
            br.readLine();
        }
        line = br.readLine();
        br.close();
        System.out.println(line);
    }
}