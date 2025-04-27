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
        "Filtered (x < 5) numbers: ".Cout(endl: false);
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
        "\nInitial numbers with dubs: ".Cout(endl: false);
        numbers2.Cout();
        var unique1 = numbers2.Unique();
        "Unique values 1: ".Cout(endl: false);
        unique1.Cout();
        
        // ============= //
        // UNIQUE 2 TEST //
        // ============= //
        var numbers3 = new List<int> { 3, 2, 3, 4, 5, 7, 4, 7, 5, 5, 6,};
        "\nInitial numbers with dubs: ".Cout(endl: false);
        numbers3.Cout();
        var unique2 = numbers3.Unique2();
        "Unique values 2: ".Cout(endl: false);
        unique2.Cout();
        
        // ================== //
        // UNIQUE 2 TIME TEST //
        // ================== //
        var numbers4 = new List<int>();
        var random = new Random();
        for (var i = 0; i < 10000; i++)
        {
            numbers4.Add(random.Next());
        }
        "\nTest for a collection of 10000 elements Unique2 algorithm time".Cout();
        numbers4.Unique2(verboseSteps: true);
        
        // ======== //
        // XOR TEST //
        // ======== //
        var setA = new List<int> { 1, 2, 3, 4, 5 };
        var setB = new List<int> { 3, 5, 6, 7 };
        "\nSet A: ".Cout(endl: false);
        setA.Cout();
        "Set B: ".Cout(endl: false);
        setB.Cout();
        var xorResult = setA.Xor(setB);
        "XOR (A ^ B): ".Cout(endl: false);
        xorResult.Cout();

        var setC = new List<string> { "apple", "banana", "cherry" };
        var setD = new List<string> { "banana", "date" };
        "\nSet C: ".Cout(endl: false);
        setC.Cout();
        "Set D: ".Cout(endl: false);
        setD.Cout();
        var xorResultString = setC.Xor(setD);
        "XOR (C ^ D): ".Cout(endl: false);
        xorResultString.Cout();
    }
}
