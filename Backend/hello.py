# Module Imports
# Note: the module name is psycopg, not psycopg3
import psycopg2

con = psycopg2.connect(database='test', user='root',
                       password='example')