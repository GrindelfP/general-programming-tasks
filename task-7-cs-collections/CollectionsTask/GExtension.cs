public static class GExtension
{
    public static IEnumerable<T> Filter(
        IEnumerable<T> collection,
        Predicate<int> predicate
    ) {
        foreach (var value in collection)
        {
            yield return predicate(value);
        }
    }
}