import requests


def count_words(subreddit, word_list, after=None, counts=None):
    if counts is None:
        counts = {word.lower(): 0 for word in word_list}

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    header = {'User-Agent': 'Mozilla/5.0'}
    params = {'limit': 100, 'after': after}
    c = requests.get(url, headers=header, params=params, allow_redirects=False)

    response = c

    if response.status_code != 200:
        return

    data = response.json().get('data', {})
    children = data.get('children', [])
    after = data.get('after')

    for child in children:
        title = child['data']['title'].lower().split()
        for word in word_list:
            count = title.count(word.lower())
            counts[word.lower()] += count

    if after:
        return count_words(subreddit, word_list, after, counts)
    else:
        sorted_counts = sorted(
            [(word, count) for word, count in counts.items() if count > 0],
            key=lambda item: (-item[1], item[0])
        )
        for word, count in sorted_counts:
            print(f"{word}: {count}")
