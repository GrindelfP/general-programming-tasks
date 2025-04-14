using System;
using System.Collections.Generic;

namespace CollectionsTask;

public static class GExtension
{
    public static IEnumerable<T> Transform<T>(this IEnumerable<T> collection, Func<T, T> transform)
    {
        foreach (var value in collection)
        {
            yield return transform(value);
        }
    }
    
    public static IEnumerable<T> Filter<T>(this IEnumerable<T> collection, Predicate<T> predicate)
    {
        foreach (var value in collection)
        {
            if (predicate(value))
            {
                yield return value;
            }
        }
    }
    
    public static T Reduce<T>(this IEnumerable<T> collection, Func<T, T, T> function)
    {
        using var iterator = collection.GetEnumerator();
        var accumulator = iterator.Current;
        while (iterator.MoveNext())
        {
            accumulator = function(accumulator, iterator.Current);
        }
        return accumulator;
    }

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
