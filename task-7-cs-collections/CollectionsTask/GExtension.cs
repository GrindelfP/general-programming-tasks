namespace CollectionsTask;

public static class GExtension
{
    public static IEnumerable<T> Filter<T>(
        this IEnumerable<T> collection,
        Predicate<T> predicate
    )
    {
        foreach (var value in collection)
        {
            if (predicate(value))
            {
                yield return value;
            }
        }
    }

    public static void ConsoleLog<T>(this IEnumerable<T> collection)
    {
        Console.Write("[");
        var notFirst = false;
        foreach (var value in collection)
        {
            if (notFirst) Console.Write(", ");
            Console.Write(value);
            notFirst = true;
        }
        Console.WriteLine("]");
    }
}
