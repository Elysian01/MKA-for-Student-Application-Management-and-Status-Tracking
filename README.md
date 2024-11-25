# Microkernel-Architecture-for-Student-Application-Management-and-Status-Tracking

---
Project works only on Linux environment

## **Core Components**

### 1. **Student Application Submission Process**
- **Description**: Handles the initial intake of student applications, ensuring all necessary information is collected and validated.
- **Functionality**:
  - Captures student data (e.g., personal details, program selection, and supporting documents).
  - Routes the application to the document verification stage.
- **Subcomponents**:
  - **Data Validation and Integrity Checker**:
    - **Description**: Ensures that all submitted application data is complete, accurate, and follows predefined formats.
    - **Functionality**: Validates fields (e.g., email format, required fields) and checks document file types and sizes.
  - **Eligibility Criteria Validator**:
    - **Description**: Verifies whether the applicant meets program-specific eligibility requirements.
    - **Functionality**: Evaluates criteria like academic scores, quotas, or prerequisites and flags ineligible applications.

### 2. **Document Verification**
- **Description**: Validates the authenticity and quality of uploaded documents required for the application.
- **Functionality**:
  - Checks for legibility, completeness, and consistency of documents (e.g., transcripts, certificates).
  - Flags missing or invalid documents for student follow-up.

### 3. **Application Status Tracker**
- **Description**: Tracks and updates the status of each application at every stage of processing.
- **Functionality**:
  - Logs application progress (e.g., Submitted, Verified, Under Review, Accepted).
  - Provides real-time updates accessible to both students and administrators.

### 4. **Student Dashboard**
- **Description**: A unified interface where students can manage their applications and view related updates.
- **Functionality**:
  - Displays application status, notifications, and pending actions.
  - Allows students to make edits, upload missing documents, or view alerts.

---

## **Extensions**

### 1. **Notifications and Alerts Manager**
- **Description**: Sends timely notifications and alerts to students regarding application updates or required actions.
- **Functionality**:
  - Generates alerts for events such as application submission confirmation, missing documents, or decision announcements.
  - Supports multiple channels (e.g., email, SMS).

### 2. **Priority Application Plugin**
- **Description**: Processes high-priority applications separately to provide faster review and response.
- **Functionality**:
  - Identifies priority applications based on criteria like merit, quotas, or early submissions.
  - Expedites application routing through status updates, document verification, and decision-making.

---

## **Flow**

### 1. **Institute**
- Open up registration and configure plugins.

### 2. **Student**
- Submit application.

### 3. **Institute**
- Perform document verification.
- Update application status.

### 4. **Student**
- Track application.
- Receive notifications.

---

## Build Instructions

### Step 1: Build the Core
Navigate to the `core/` directory and run:
```bash
cd core
make
```

### Step 2: Build the Plugins
Navigate to the `plugins/` directory and run:
```bash
cd plugins
make
```

### Step 3: Run the Core
Return to the project root and execute the core:
```bash
./core/core
```

### Step 4: Select a Plugin
When prompted, select the plugin you wish to load. For example:
```
Core system started.
Available Plugins:
1. ./plugins/notification_manager.so
2. ./plugins/priority_application_plugin.so
Enter the number of the plugin to load (or 0 to exit): 1
Loading plugin: ./plugins/notification_manager.so
Notification Manager Plugin initialized!
```

## Cleaning Up
Run `make clean` in both `core/` and `plugins/` directories to clean up the generated files.
