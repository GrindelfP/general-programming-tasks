namespace CollectionsTask;

public static class GExtension
{
    public static IEnumerable<T> Filter<T>(
        IEnumerable<T> collection,
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
}