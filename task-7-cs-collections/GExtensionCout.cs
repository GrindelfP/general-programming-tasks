namespace CollectionsTask;

public static class GExtensionCout
{
    public static void Cout<T>(this IEnumerable<T> collection, bool endl = true)
    {
        Console.Write("[");
        var notFirst = false;
        foreach (var value in collection)
        {
            if (notFirst) Console.Write(", ");
            Console.Write(value);
            notFirst = true;
        }

        Console.Write("]");
        if (endl) Console.WriteLine();
    }

    // public static void Cout<T>(this T data, bool endl = true)
    // {
    //     Console.Write(data);
    //     if (endl) Console.WriteLine();
    // }

    public static void Cout(this int integer, bool endl = true)
    {
        Console.Write(integer);
        if (endl) Console.WriteLine();
    }

    public static void Cout(this string line, bool endl = true)
    {
        Console.Write(line);
        if (endl) Console.WriteLine();
    }
}