import sqlite3

class Database:
    def __init__(self, db_name="course_management.db"):
        self.db_name = db_name
        self.create_tables()
    
    def get_connection(self):
        return sqlite3.connect(self.db_name)
    
    def create_tables(self):
        conn = self.get_connection()
        cursor = conn.cursor()

        # ตาราง users
        cursor.execute('''
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL,
            full_name TEXT NOT NULL,
            role TEXT DEFAULT 'student',
            created_at TEXT DEFAULT CURRENT_TIMESTAMP
        )
        ''')

        # ตาราง courses
        cursor.execute('''
        CREATE TABLE IF NOT EXISTS courses (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            course_code TEXT UNIQUE NOT NULL,
            course_name TEXT NOT NULL,
            description TEXT,
            credits INTEGER,
            instructor TEXT,
            created_at TEXT DEFAULT CURRENT_TIMESTAMP
        )
        ''')

        # ตาราง enrollments
        cursor.execute('''
        CREATE TABLE IF NOT EXISTS enrollments (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER,
            course_id INTEGER,
            grade REAL,
            status TEXT DEFAULT 'enrolled',
            enrolled_at TEXT DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY (user_id) REFERENCES users (id),
            FOREIGN KEY (course_id) REFERENCES courses (id)
        )
        ''')

        conn.commit()
        conn.close()

        self.insert_sample_data()

    def insert_sample_data(self):
        conn = self.get_connection()
        cursor = conn.cursor()
        
        cursor.execute("SELECT COUNT(*) FROM users")
        if cursor.fetchone()[0] == 0:

            cursor.execute('''
INSERT INTO users (username, password, full_name, role) VALUES (?, ?, ?, ?)
''', ('admin', 'admin123', 'ผู้ดูแลระบบ', 'admin'))
            
            cursor.execute('''
INSERT INTO users (username, password, full_name, role) VALUES (?, ?, ?, ?)
''', ('student1', 'pass123', 'สมชาย ใจดี', 'student'))
            
            cursor.execute('''
INSERT INTO users (username, password, full_name, role) VALUES (?, ?, ?, ?)
''', ('student2', 'pass123', 'สมหญิง รักเรียน', 'student'))
            
        cursor.execute("SELECT COUNT(*) FROM courses")
        if cursor.fetchone()[0] == 0:

            courses = [
                ('CS101', 'Introduction to Programming', 'เรียนรู้พื้นฐานการเขียนโปรแกรม', 3, 'อ.สมศักดิ์'),
                ('CS102', 'Data Structures', 'โครงสร้างข้อมูลและอัลกอริทึม', 3, 'อ.วิชัย'),
                ('CS201', 'Database Systems', 'ระบบฐานข้อมูล', 3, 'อ.สมหมาย'),
                ('CS202', 'Web Development', 'การพัฒนาเว็บไซด์', 3, 'อ.นภา'),
                ('CS301', 'Software Engineering', 'วิศวกรรมซอฟต์แวร์', 3, 'อ.ประสิทธิ์')
            ]
            cursor.executemany('''
            INSERT INTO courses (course_code, course_name, description, credits, instructor) VALUES (?, ?, ?, ?, ?)
            ''', courses)
            
        conn.commit()
        conn.close()
        
    def authenticate_user(self, username, password):
        conn = self.get_connection()
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM users WHERE username=? AND password=?", (username, password))
        user = cursor.fetchone()
        conn.close()
        return user

    def get_user_by_id(self, user_id):
        conn = self.get_connection()
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM users WHERE id=?", (user_id,))
        user = cursor.fetchone()
        conn.close()
        return user
    
    def get_all_users(self):
        conn = self.get_connection()
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM users")
        users = cursor.fetchall()
        conn.close()
        return users

    def get_all_courses(self):
        conn = self.get_connection()
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM courses")
        courses = cursor.fetchall()
        conn.close()
        return courses
    
    def add_user(self, username, password):
        conn = self.get_connection()
        cursor = conn.cursor()
        cursor.execute(
            "INSERT INTO users (username, password, full_name) VALUES (?, ?, ?)",
            (username, password, "Unknown")   
        )
        conn.commit()
        conn.close()
        return True

    def add_course(self, course_code, course_name, description, credits, instructor):
        conn = self.get_connection()
        cursor = conn.cursor()
        cursor.execute("INSERT INTO courses (course_code, course_name, description, credits, instructor) VALUES (?, ?, ?, ?, ?)", (course_code, course_name, description, credits, instructor))
        conn.commit()
        conn.close()
        return True

    def update_user(self, user_id, username, password):
        conn = self.get_connection()
        cursor = conn.cursor()
        cursor.execute("UPDATE users SET username=?, password=? WHERE id=?", (username, password, user_id))
        conn.commit()
        conn.close()
        return True

    def update_course(self, course_id, course_code, course_name, description, credits, instructor):
        conn = self.get_connection()
        cursor = conn.cursor()
        cursor.execute("UPDATE courses SET course_code=?, course_name=?, description=?, credits=?, instructor=? WHERE id=?", (course_code, course_name, description, credits, instructor, course_id))
        conn.commit()
        conn.close()
        return True

    def delete_user(self, user_id):
        conn = self.get_connection()
        cursor = conn.cursor()
        cursor.execute("DELETE FROM users WHERE id=?", (user_id,))
        conn.commit()
        conn.close()
        return True

    def delete_course(self, course_id):
        conn = self.get_connection()
        cursor = conn.cursor()
        cursor.execute("DELETE FROM courses WHERE id=?", (course_id,))
        conn.commit()
        conn.close()
        return True

    def enroll_course(self, user_id, course_id):
        conn = self.get_connection()
        cursor = conn.cursor()
        cursor.execute("INSERT INTO enrollments (user_id, course_id) VALUES (?, ?)", (user_id, course_id))
        conn.commit()
        conn.close()
        return True
    
    def get_user_enrollments(self, user_id):
        conn = self.get_connection()
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM enrollments WHERE user_id=?", (user_id,))
        enrollments = cursor.fetchall()
        conn.close()
        return enrollments
    
    def get_course_enrollments(self, course_id):
        conn = self.get_connection()
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM enrollments WHERE course_id=?", (course_id,))
        enrollments = cursor.fetchall()
        conn.close()
        return enrollments
    
    def update_grade(self, enrollment_id, grade):
        conn = self.get_connection()
        cursor = conn.cursor()
        cursor.execute("UPDATE enrollments SET grade=? WHERE id=?", (grade, enrollment_id))
        conn.commit()
        conn.close()
        return True
    
    def drop_enrollment(self, enrollment_id):
        conn = self.get_connection()
        cursor = conn.cursor()
        cursor.execute("DELETE FROM enrollments WHERE id=?", (enrollment_id,))
        conn.commit()
        conn.close()
        return True
        