namespace CollectionsTask;

public static class Program
{
    public static void Main()
    {
        var numbers = Enumerable.Range(0, 100).ToList();
        var filteredNumbers = numbers.Filter(number => number < 20);

        numbers.ConsoleLog();
        filteredNumbers.ConsoleLog();
    }
}
