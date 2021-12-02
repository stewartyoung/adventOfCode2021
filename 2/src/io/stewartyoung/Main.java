package io.stewartyoung;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
	// write your code here
        int horizontal = 0;
        int depth = 0;
        int aim = 0;
        int depth2 = 0;
        File input = new File("data/input.txt");
        Scanner reader = new Scanner(input);
        while (reader.hasNextLine()) {
            String data = reader.nextLine();
            String[] dataArray = data.split("\\s+");
            String direction = dataArray[0];
            int quantity = Integer.parseInt(dataArray[1]);
            System.out.println(direction);
            System.out.println(quantity);

            switch(direction){
                case "up":
                    depth = depth - quantity;
//                    depth2 = depth2 - quantity;
                    aim = aim - quantity;
                    break;
                case "down":
                    depth = depth + quantity;
//                    depth2 = depth2 + quantity;
                    aim = aim + quantity;
                    break;
                case "forward":
                    horizontal = horizontal + quantity;
                    depth2 = depth2 + aim * quantity;
                    break;
            }

            System.out.println("horizontal: " + horizontal);
            System.out.println("depth: " + depth);
            System.out.println("depth2: " + depth2);
            System.out.println("aim: " + aim);
        }
        System.out.println("horizontal: " + horizontal + " depth: " + depth);
        int horizontalXDepth = horizontal * depth;
        System.out.println(horizontalXDepth);

        int horizontalXDepth2 = horizontal * depth2;
        System.out.println(horizontalXDepth2);

        reader.close();
    }
}
