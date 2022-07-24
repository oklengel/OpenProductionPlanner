# This is a sample Python script.

import os
import sys
from flask import Flask
import io
import random
from flask import Response
import mysql.connector
from mysql.connector import Error

try:
    print(os.environ["MYSQL_HOST"])
    print(os.environ["MYSQL_DATABASE"])
    print(os.environ["MYSQL_PORT"])
    print(os.environ["MYSQL_USER"])
    print(os.environ["MYSQL_PASSWORD"])
except KeyError as e:
    print("Needed environment variable is not set: ", e, file=sys.stderr)

app = Flask(__name__)


@app.route("/")
def hello():
    ret = False
    conn = None
    try:
        conn = mysql.connector.connect(host=os.environ["MYSQL_HOST"],
                                       port=os.environ["MYSQL_PORT"],
                                       database=os.environ["MYSQL_DATABASE"],
                                       user=os.environ["MYSQL_USER"],
                                       password=os.environ["MYSQL_PASSWORD"])
        if conn.is_connected():
            print('Connected to MySQL database')
            ret = True
        else:
            print('Not connected to MySQL database')

        # TODO Fetch/Insert/Update stuff from/to DB

    except Error as e:
        print('Failed to connect to MySQL database', e, file=sys.stderr)

    finally:
        if conn is not None and conn.is_connected():
            conn.close()

    return "Hello, World!" + " Connected to DB" if ret else " Not Connected to DB"




def connect():
    """ Connect to MySQL database """
    ret = False

    return ret
