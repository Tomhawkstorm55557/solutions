# Write your MySQL query statement below
#Write a solution to find the IDs of the invalid tweets. The tweet is invalid if the number of characters used in the content of the tweet is strictly greater than 15.
SELECT tweet_id FROM Tweets where  CHAR_LENGTH(content)>15