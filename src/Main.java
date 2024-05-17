import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
public class Main {
    public static void main(String[] args) throws IOException {
        

            File file = new File("/Users/christineswann/Documents/GitHub/JavaCppTest1/text/Data1.txt");
            FileWriter fr = new FileWriter(file, true);
            BufferedWriter br = new BufferedWriter(fr);
            br.write("Writing from the java file!!!!");
            br.close();
           

    }
}