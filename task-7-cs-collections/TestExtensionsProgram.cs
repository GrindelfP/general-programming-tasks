namespace CollectionsTask;

public static class TestExtensionsProgram
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

        // =========== //
        // UNIQUE TEST //
        // =========== //
        var numbers2 = new List<int> { 1, 2, 3, 4, 5, 5, 5, 6, 7, 7, 7 };
        "\nInitial numbers wit dubs: ".Cout(endl: false);
        numbers2.Cout();
        var unique1 = numbers2.Unique();
        "\nUnique values 1: ".Cout(endl: false);
        unique1.Cout();
        
        
    }
}