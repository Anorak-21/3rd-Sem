class MainException{
	public static void main(String args[]){
		try {
    // some code that throws an exception
    throw new MyException("This is my custom error message.");
} catch (MyException e) {
    System.out.println(e.getMessage());
}
}}

class MyException extends Exception {
    public MyException(String errorMessage) {
        super(errorMessage);
    }
}