package io.stewartyoung;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
	// write your code here
        int horizontal = 0;
        int depth = 0;
        File input = new File("data/input.txt");
        Scanner reader = new Scanner(input);
        while (reader.hasNextLine()) {
            String data = reader.nextLine();
            String[] dataArray = data.split("\\s+");
            String direction = dataArray[0];
            String quantity = dataArray[1];
            System.out.println(direction);
            System.out.println(quantity);

            switch(direction){
                case "up":
                    depth = depth - Integer.parseInt(quantity);
                    break;
                case "down":
                    depth = depth + Integer.parseInt(quantity);
                    break;
                case "forward":
                    horizontal = horizontal + Integer.parseInt(quantity);
                    break;
            }

            System.out.println("horizontal: " + horizontal);
            System.out.println("depth: " + depth);
        }
        System.out.println("horizontal: " + horizontal + " depth: " + depth);
        int horizontalXDepth = horizontal * depth;
        System.out.println(horizontalXDepth);
        reader.close();
    }
}
