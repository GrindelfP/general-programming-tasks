namespace CollectionsTask;

public static class GExtensionCollections
{
    public static IEnumerable<T> Transform<T>(this IEnumerable<T> collection, Func<T, T> transformer)
    {
        foreach (var value in collection)
        {
            yield return transformer(value);
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

    /// <summary>
    /// Returns collection of unique values for a given collection
    /// with possible duplicate values.
    /// </summary>
    /// 
    /// <param name="collection">
    /// Initial collection
    /// </param>
    /// 
    /// <typeparam name="T">
    /// Type of the elements of the colllection.
    /// </typeparam>
    /// 
    /// <returns>
    /// Collection of unique values out of initial collection.
    /// </returns>
    public static IEnumerable<T> Unique<T>(this IEnumerable<T> collection)
    {
        using var iterator = collection.GetEnumerator();
        var value = iterator.Current;
        yield return value;
        while (iterator.MoveNext())
        {
            if (!value!.Equals(iterator.Current))
            {
                value = iterator.Current;
                yield return value;
            }
        }
    }
}
