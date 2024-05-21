import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
public class Main {
    public static void main(String[] args) throws IOException {
        try {

            String filename = "Data1.txt";
            String workingDirectory = System.getProperty("user.dir");

            //****************//

            String absoluteFilePath = "";

            //absoluteFilePath = workingDirectory + System.getProperty("file.separator") + filename;
            absoluteFilePath = workingDirectory + File.separator + filename;

            System.out.println("Final filepath : " + absoluteFilePath);

            //****************//

            File file = new File(absoluteFilePath);

            if (file.createNewFile()) {
                    System.out.println("File is created!");
                } else {
                    System.out.println("File is already existed!");
                }

        } catch (IOException e) {
            e.printStackTrace();
        }
        FileWriter fr = new FileWriter(file, true);
        BufferedWriter br = new BufferedWriter(fr);
        br.write("Writing from the java file!!!!");
        br.close();
    }
}