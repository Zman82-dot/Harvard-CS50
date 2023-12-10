-- Keep a log of any SQL queries you execute as you solve the mystery.
--Preliminary Investigation
SELECT * FROM crime_scene_reports WHERE year = 2021 AND month=7 AND day = 28;

-- Gathering more information from witnesses.

SELECT transcript FROM interviews WHERE year = 2021 AND month=7 AND day = 28;

--Checking bank accounts of time frame the witness "Eugene says the suspect made a withdrawal from the bank on Leggett street

SELECT name FROM people JOIN bank_accounts ON bank_accounts.person_id = people.id JOIN atm_transactions ON bank_accounts.person_id =people.id WHERE atm_location ="Leggett Street"
AND year =2021 AND month = 7 AND day = 28 AND transaction_type="withdraw" ORDER BY name ASC LIMIT 800;
--next line--
SELECT account_number, amount FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location ="Leggett Street"
AND transaction_type = "withdraw";
 next line--
SELECT name, atm_transactions.amount FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions
WHERE atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28
AND atm_transactions.atm_location = "Leggett Street"
AND atm_transactions.transaction_type = "withdraw" ORDER BY name DESC;
-- Investigating the time frame where witnes says the crime took place finding out who was recorded by security logs during the witness time frame.
SELECT name, bakery_security_logs.hour, bakery_security_logs.minute, people.license_plate
FROM people JOIN bakery_security_logs ON people.license_plate
WHERE bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28 AND bakery_security_logs.activity ="exit"
AND bakery_security_logs.hour = 10  AND bakery_security_logs.minute >= 15 AND bakery_security_logs.minute <=25 AND name = "Bruce"
ORDER BY bakery_security_logs.minute;
SELECT name, phone_calls.duration
--Checking call logs to see which to gather clues on  phone record during time frame of witness accounts.
FROM people JOIN phone_calls ON people.phone_number=phone_calls.caller
WHERE phone_calls.year=2021 AND phone_calls.month=7 AND phone_calls.day=28 AND phone_calls.duration <= 60
ORDER BY phone_calls.duration;
-- Gathering more detailed call record in information
SELECT name, phone_calls.duration
FROM people JOIN phone_calls ON people.phone_number=phone_calls.receiver
WHERE phone_calls.year=2021 AND phone_calls.month=7 AND phone_calls.day=28 AND phone_calls.duration <= 60
ORDER BY phone_calls.duration;
--Investigating flight records with given suspected offenders being narrowed down thru gathering information from witness accounts getting close to suspect.
SELECT flights.id, city ,flights.hour,flights.minute FROM airports
JOIN flights ON airports.id= flights.destination_airport_id
WHERE flights.origin_airport_id =(
    SELECT id FROM airports WHERE city ='Fiftyville')
    AND flights.year = 2021 AND flights.month = 7 AND flights.day =29;
--Matching flight information with passenger information
SELECT * FROM airports;
--n--


SELECT passengers.flight_id, name, passengers.passport_number,passengers.seat,flights.hour,flights.day
FROM people JOIN passengers ON people.passport_number = passengers.passport_number JOIN flights ON passengers.flight_id = flights.id
WHERE flights.year = 2021 AND flights.month = 7 AND flights.day = 29 ORDER BY flights.hour;

-- After thorough investigation we have come to announce the suspects and associated parties.
--The thief is Bruce and the Accomplice is Robin For the reasons as followed.
--Bruce and Robin were both in the bakery during the time the theft was taken place down to the second! and because of their sloppyness the left behind many clues.
--Bruce & Robin were on the phione during the time in question again exactly down to the second !
-- Bruce & Robin were both in the parking exactly at the same time and left the same time i guess they were trying to be discreet and slick by sitting in different cars .
--Bruce withdrew money on his way to the bakery that was his spending money  and Robin went back later to withdraw money to buy his ticket the whole thing is pre-meditated and awfully planned .
--Matching passenger information with flight and airport information we have concluded Bruce fled to New York.