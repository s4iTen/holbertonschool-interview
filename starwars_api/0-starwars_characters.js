#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];

if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <Movie ID>');
  process.exit(1);
}

const url = `https://swapi.dev/api/films/${movieId}/`;

request(url, (error, response, body) => {
  if (error) {
    console.error('Error:', error);
    process.exit(1);
  }

  if (response.statusCode !== 200) {
    console.error('Failed to fetch data. Status code:', response.statusCode);
    process.exit(1);
  }

  const film = JSON.parse(body);
  if (!film.characters || film.characters.length === 0) {
    console.error('No characters found for this movie.');
    process.exit(1);
  }

  const charactersUrls = film.characters;
  const charactersPromises = charactersUrls.map(characterUrl => {
    return new Promise((resolve, reject) => {
      request(characterUrl, (err, resp, charBody) => {
        if (err) {
          reject(err);
        } else {
          const character = JSON.parse(charBody);
          resolve(character.name);
        }
      });
    });
  });

  Promise.all(charactersPromises)
    .then(characters => {
      characters.forEach(character => console.log(character));
    })
    .catch(err => {
      console.error('Error fetching characters:', err);
      process.exit(1);
    });
});