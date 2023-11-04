class MainWild{
    public static <T extends Comparable<T>> T findMax(T[] array) {
        if (array == null || array.length == 0) {
            return null;
        }

        T max = array[0];

        for (T item : array) {
            if (item.compareTo(max) > 0) {
                max = item;
            }
        }

        return max;
    }

    public static void main(String[] args) {
        // Create an array of integers
        Integer[] integers = {4, 7, 2, 9, 1};
        Integer maxInteger = findMax(integers);
        System.out.println("Maximum integer: " + maxInteger);

        // Create an array of doubles
        Double[] doubles = {3.14, 2.71, 1.618, 0.577};
        Double maxDouble = findMax(doubles);
        System.out.println("Maximum double: " + maxDouble);

        // Create an array of strings
        String[] strings = {"apple", "banana", "cherry"};
        String maxString = findMax(strings);
        System.out.println("Maximum string: " + maxString);
    }
}
