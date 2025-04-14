using System.Diagnostics.CodeAnalysis;

namespace CollectionsTask;

public static class Program
{
    public static void Main()
    {
        var numbers = Enumerable.Range(0, 100).ToList();
        var filteredNumbers = GExtension.Filter(numbers, number => number < 20);

        Console.WriteLine(string.Join(", ", numbers));
        foreach (var number in filteredNumbers)
        {
            Console.Write(number + ", ");
        }
    }
}
