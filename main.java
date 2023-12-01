import java.util.ArrayList;
import java.util.Scanner;

class User {
    private String name;
    private String phoneNumber;

    public User(String name, String phoneNumber) {
        this.name = name;
        this.phoneNumber = phoneNumber;
    }

    public String getName() {
        return name;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    @Override
    public String toString() {
        return "Name: " + name + ", Phone Number: " + phoneNumber;
    }
}

class UserManager {
    private ArrayList<User> userList;

    public UserManager() {
        userList = new ArrayList<>();
    }

    public void addUser(String name, String phoneNumber) {
        User newUser = new User(name, phoneNumber);
        userList.add(newUser);
        System.out.println("User added successfully.");
    }

    public void deleteUser(String name) {
        for (User user : userList) {
            if (user.getName().equalsIgnoreCase(name)) {
                userList.remove(user);
                System.out.println("User deleted successfully.");
                return;
            }
        }
        System.out.println("User not found.");
    }

    public void viewUsers() {
        if (userList.isEmpty()) {
            System.out.println("No users found.");
        } else {
            System.out.println("User List:");
            for (User user : userList) {
                System.out.println(user);
            }
        }
    }
}

public class UserManagementSystem {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        UserManager userManager = new UserManager();

        while (true) {
            System.out.println("\n1. Add User");
            System.out.println("2. Delete User");
            System.out.println("3. View Users");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            switch (choice) {
                case 1:
                    System.out.print("Enter name: ");
                    String addName = scanner.nextLine();
                    System.out.print("Enter phone number: ");
                    String addPhoneNumber = scanner.nextLine();
                    userManager.addUser(addName, addPhoneNumber);
                    break;

                case 2:
                    System.out.print("Enter name to delete: ");
                    String deleteName = scanner.nextLine();
                    userManager.deleteUser(deleteName);
                    break;

                case 3:
                    userManager.viewUsers();
                    break;

                case 4:
                    System.out.println("Exiting program. Goodbye!");
                    System.exit(0);

                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        }
    }
}
