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
    /// Type of the elements of the collection.
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

    /// <summary>
    /// Returns collection of unique values for a given unordered
    /// collection with possible duplicate values.
    /// 
    /// Performs with linear time.
    /// </summary>
    /// 
    /// <param name="collection">
    /// Initial collection
    /// </param>
    /// <param name="verboseSteps">
    /// Whether print number of steps taken to complete the process or not.
    /// </param>
    /// 
    /// <typeparam name="T">
    /// Type of the elements of the collection.
    /// </typeparam>
    /// 
    /// <returns>
    /// Collection of unique values out of initial collection.
    /// </returns>
    public static IEnumerable<T> Unique2<T>(this IEnumerable<T> collection, bool verboseSteps = false)
    {
        var counter = 0;
        using var iterator = collection.GetEnumerator();
        var set = new HashSet<T>();
        while (iterator.MoveNext())
        {
            counter++;
            set.Add(iterator.Current);
        }

        if (verboseSteps) counter.Cout();
        
        return set;
    }
    
    /// <summary>
    /// Performs XOR operation over given two sets.
    /// </summary>
    /// 
    /// <param name="thisCollection">
    /// First set.
    /// </param>
    /// 
    /// <param name="other">
    /// Second set.
    /// </param>
    /// 
    /// <typeparam name="T">
    /// Set's values type.
    /// </typeparam>
    /// 
    /// <returns>
    /// Resulting set.
    /// </returns>
    public static IEnumerable<T> Xor<T>(this IEnumerable<T> thisCollection, IEnumerable<T> other)
    {
        throw new NotImplementedException();
    }
}
