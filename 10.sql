SELECT NAME FROM PEOPLE WHERE ID IN(SELECT PERSON_ID FROM DIRECTORS WHERE MOVIE_ID IN (SELECT MOVIE_ID FROM RATINGS WHERE RATING >= 9.0));