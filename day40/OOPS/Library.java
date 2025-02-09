class LibraryBook {
    private String title;
    private String author;
    private boolean isAvailable;

    // Constructor
    public LibraryBook(String title, String author) {
        this.title = title;
        this.author = author;
        this.isAvailable = true; // By default, the book is available
    }

    // Getter methods
    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public boolean isAvailable() {
        return isAvailable;
    }

    // Method to borrow a book
    public void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            System.out.println("You have borrowed: " + title);
        } else {
            System.out.println("Sorry, " + title + " is already borrowed.");
        }
    }

    // Method to return a book
    public void returnBook() {
        isAvailable = true;
        System.out.println("You have returned: " + title);
    }

    public static void main(String[] args) {
        LibraryBook book1 = new LibraryBook("1984", "George Orwell");
        book1.borrowBook();
        book1.returnBook();
    }
}