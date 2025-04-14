using System.Linq;

namespace CollectionsTask;

public static class Program
{
    public static void Main()
    {
        var numbers = Enumerable.Range(0, 10).ToList();
        "Initial numbers: ".Cout(endl: false);
        numbers.Cout();

        // =========== //
        // FILTER TEST //
        // =========== //
        var filteredNumbers = numbers.Filter(number => number < 5);
        "\nFiltered (x < 5) numbers: ".Cout(endl: false);
        filteredNumbers.Cout();
        
        // =========== //
        // REDUCE TEST //
        // =========== //
        var reducedNumbers = numbers.Reduce((a, b) => a + b);
        "\nReduced numbers (rule x_i = x_i + x_{i+1}): ".Cout(endl: false);
        reducedNumbers.Cout();
        
        // ============== //
        // TRANSFORM TEST //
        // ============== //
        var transformedNumbers = numbers.Transform(a => -a);
        "\nTransformed (-1 * x) numbers: ".Cout(endl: false);
        transformedNumbers.Cout();
    }
}
