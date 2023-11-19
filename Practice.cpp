static int minSegmentsForHigherScore(int[] segments)
{
    int scoreP1 = 0, scoreP2 = 0;
    int minSegments = segments.length + 1;

    for (int i = 0; i <= segments.length; ++i)
    {
        int remainingSegments = segments.length - i;
        int scoreDiff = scoreP2 - remainingSegments;

        if (scoreP1 > scoreP2 || (scoreP1 == scoreP2 && scoreDiff < 0))
        {
            minSegments = Math.min(minSegments, i);
        }

        if (i < segments.length)
        {
            if (segments[i] == 1)
            {
                ++scoreP1;
            }
            else
            {
                --scoreP1;
            }
        }
    }

    return (minSegments > segments.length) ? -1 : minSegments;
}