CREATE TABLE flights (
    id SERIAL PRIMARY KEY,

    name TEXT NOT NULL,
    input_dir TEXT NOT NULL,

    flight_status TEXT NOT NULL DEFAULT 'queued'
        CHECK (flight_status IN (
            'queued',
            'processing',
            'completed',
            'completed_with_errors',
            'failed',
            'cancelled'
        )),

    total_images INT NOT NULL DEFAULT 0,
    processed_images INT NOT NULL DEFAULT 0,
    failed_images INT NOT NULL DEFAULT 0,

    created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    started_at TIMESTAMP,
    finished_at TIMESTAMP,

    UNIQUE (input_dir)
);

CREATE TABLE flight_images (
    id SERIAL PRIMARY KEY,

    flight_id INT NOT NULL REFERENCES flights(id) ON DELETE CASCADE,

    image_name TEXT NOT NULL,
    image_path TEXT NOT NULL,

    image_status TEXT NOT NULL DEFAULT 'queued'
        CHECK (image_status IN (
            'queued',
            'processing',
            'completed',
            'failed',
            'skipped'
        )),

    error TEXT,

    created_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    started_at TIMESTAMP,
    finished_at TIMESTAMP,

    UNIQUE (flight_id, image_path)
);