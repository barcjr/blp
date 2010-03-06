import random
import sys

# v, w, k, n, a - 0-9 - (1,2)x(1,2,3)
def gen_callsign(call_seed):
    random.seed(call_seed)
    #n_letter = call_seed % 5
    #call_seed = int(call_seed / 5)
    #n_chars1 = (call_seed % 2)
    #call_seed = int(call_seed / 2)
    #n_chars2 = 1 + (call_seed % 3)
    #call_seed = int(call_seed / 3)
    #n_sec = call_seed % 10
    #call_seed = int(call_seed / 10)
    n_letter = random.randint(0,4)
    n_chars1 = random.randint(0,1)
    n_chars2 = random.randint(1,3)
    n_sec = random.randint(0,4)
    letters = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
    prefixes = ['V','W','K','N','A']
    callsign = ""
    callsign += prefixes[n_letter]
    if( n_chars1 > 0 ):
        callsign += random.choice(letters)
    callsign += str(n_sec)
    for i in range(0, n_chars2):
        callsign += random.choice(letters)
    return callsign

def gen_class(class_seed):
    random.seed(class_seed)
    n_type = random.choice(['A','B','C','D','E','F'])
    if(random.randint(0,5) == 0):
        n_num = random.randint(0,30)
    else:
        n_num = random.randint(0,9)
    return str(n_num) + n_type

def gen_section(section_seed):
    random.seed(section_seed)
    return random.choice(['AL','AK','AB','AZ','AR','BC','CO','CT','DE','EB','EMA','ENY','EPA','EWA','GA','ID','IL','IN','IA','KS','KY','LAX','LA','ME','MB','MAR','MDC','MI','MN','MS','MO','MT','NE','NV','NH','NM','NL','NC','ND','NTX','NFL','NNJ','NNY','NT','NLI','OH','OK','ON','ORG','OR','PAC','PR','QC','RI','SV','SDG','SF','SJV','SB','SCV','SK','SC','SD','STX','SFL','SNJ','TN','UT','VT','VI','VA','WCF','WTX','WV','WMA','WNY','WPA','WWA','WI','WY'])

if(sys.argv[1] != "check"):
    for i in range(0,300):
        print gen_callsign(i) + "\t" + gen_class(i) + "\t" + gen_section(i)
else:
    import MySQLdb
    db = MySQLdb.connect(host="localhost", user="root")
    c = db.cursor()
    c.execute("use FieldDay;");
    for i in range(0,300):
        c.execute("SELECT ContestClass, Section.Abbr FROM Station JOIN Section ON (Station.SectionID=Section.SectionID) WHERE Station.StationCall = \'" + gen_callsign(i) + "\';")
        
        row = c.fetchone()
        if(row == None):
            print "Error... station not in database: " + gen_callsign(i) + "\n"
        elif(row[0] != gen_class(i)):
            print "Error... class mismatch: " + gen_class(i) + " != " + row[0] + "\n"
        elif(row[1] != gen_section(i)):
            print "Error... section mismatch: " + gen_section(i) + " != " + row[1] + "\n"
        
